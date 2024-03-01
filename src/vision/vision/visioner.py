import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2 as cv
import numpy as np

"""
Class untuk menghandle penglihatan bot dan juga menggambar gerakan bot
"""
class VisionerTicTacToe(Node):

    def __init__(self):
        super().__init__('VisionerTicTacToe')

        cv.namedWindow("ni olel")                                           #window dibutuhkan supaya dapat menggunakan trackbar                                         #window dibutuhkan supaya dapat menggunakan trackbar
        cv.createTrackbar('minArea', 'ni olel', 81000, 307200, self.nothing)#trackbar untuk kalibrasi area contours deteksi grid
        cv.createTrackbar('param2', 'ni olel', 15, 200, self.nothing)       #trackbar untuk kalibrasi akurasi deteksi lingkaran terhadap kualitas cahaya
        
        #buka camera
        self.cap = cv.VideoCapture(4)
        if not self.cap.isOpened():
            print("HUAAAAAAAAAA RUSAAAAAAAAAAAK")
        
        #array untuk menyimpan grid mana saja yang ditempati oleh bot
        self.botMoves = np.array([])
        
        #membuat publisher dan memanggil method 'timer_callback()' 30 kali sedetik
        self.publisher_ = self.create_publisher(String, 'ttt_state', 10)
        timer_period = 0.032  # seconds | 30 fps
        self.timer = self.create_timer(timer_period, self.timer_callback)

        #membuat subscription untuk menerima perintah gerakan bot
        self.subscription = self.create_subscription(
            String,
            'ttt_moves',
            self.listener_callback,
            10)
        self.subscription #ini biar ga di warning bjir

        print("constructor excuted")

    #dummy method sebagai callback function dari trackbar
    def nothing(self):
        pass
    
    #method untuk mencari posisi grid
    def findGrid(self, frame):

        pos1 = np.array([0, 0])
        pos2 = np.array([1, 1])

        lowerBound = np.array([140, 150, 100], dtype=np.uint8)
        upperBound = np.array([255, 255, 255], dtype=np.uint8)

        frame = cv.inRange(frame, lowerBound, upperBound)
        contours, _ = cv.findContours(frame, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
        # cv.drawContours(self.drawnFrame, contours, -1, (0, 255, 0), 3)

        for contour in contours:
            x, y, w, h = cv.boundingRect(contour)
            area = cv.contourArea(contour)

            # If the area of the contour is within a certain range, draw a bounding box
            if self.pram1 < area < self.pram1 + 2000:
                color = (0, 0, 255)  # Red color for the bounding box
                thickness = 2
                cv.rectangle(self.drawnFrame, (x, y), (x + w, y + h), color, thickness)
                pos1[0] = x
                pos1[1] = y
                pos2[0] = x + w
                pos2[1] = y + h

        # cv.imshow("tes1", frame)
        # print(pos2)
        # print(pos1)
        return pos1, pos2


    """
    Method untuk membaca keadaan grid.
    karena method ini terpanggil 30 kali perdetik, maka method ini dapat membaca kamera, memproses, dan 
    menampilkannya ke layar. Hasil proses diubah kebentuk string agar lebih mudah untuk dikirim. Method
    ini me-return string yang telah di proses tadi apabila user menekan tombol "x" yang menandakan pergantian
    giliran.
    """
    def readState(self):
        #membaca frame kamera
        successOpenCam, self.drawnFrame = self.cap.read()
        if not successOpenCam:
            print("NDAK BISA BACA HUAAA")
            return
        
        #buat copy dari self.drawnFrame dengan nama processFrame yang akan kita gunakan untuk memproses
        processFrame = self.drawnFrame.copy()
        
        self.pram1 = int(cv.getTrackbarPos('minArea', 'ni olel')) #upper threshold yang di pass ke canny edge detector, sebagai parameter yang dapat diubah dari trackbar
        pram2 = int(cv.getTrackbarPos('param2', 'ni olel')) #tingkat akurasi deteksi lingkaran tergantung pada kualitas cahaya, sebagai parameter yang dapat diubah dari trackbar
       
        #mencari posisi dari grid
        self.gridCorner1, self.gridCorner2 = self.findGrid(self.drawnFrame.copy())
        
        #menutupi area yang tidak perlu untuk menghindari deteksi lingkaran yang tidak diinginkan
        processFrame = cv.rectangle(processFrame, (0, 0 ), (self.gridCorner1[0], 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (self.gridCorner1[0], 0), (self.gridCorner2[0], self.gridCorner1[1]), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (self.gridCorner2[0], 0), (640, 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (self.gridCorner1[0], self.gridCorner2[1]), (self.gridCorner2[0], 480), (0, 0, 0), -1)

        #convert ke hsv dan apply blur
        processFrame = cv.cvtColor(processFrame, cv.COLOR_BGR2HSV)
        processFrame = cv.medianBlur(processFrame, 5)

        #buat dua foto copy yang nanti digabung karena merah memiliki 2 interval hsv
        mask1 = processFrame.copy()
        mask2 = processFrame.copy()
        
        #mask untuk nilai hsv merah yang pertama
        upper_range = np.array([15, 255, 255])
        lower_range = np.array([0, 100, 100])
        mask1 = cv.inRange(mask1, lower_range, upper_range)

        #mask untuk nilai hsv merah yang kedua
        upper_range = np.array([179, 255, 255])
        lower_range = np.array([155, 100, 100])
        mask2 = cv.inRange(mask2, lower_range, upper_range)

        #gabungkan kedua mask untuk mendapatkan semua warna merah
        processFrame = mask1 + mask2
        

        #deteksi lingkaran
        circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1, 60, param1 = 100, param2 = pram2, minRadius = 0, maxRadius = 0)
            
        boxLenX = (self.gridCorner2[0] - self.gridCorner1[0])/3 
        boxLenY = (self.gridCorner2[1] - self.gridCorner1[1])/3 
        #batas batas tiap kolom di grid dan juga index kolomnya
        gridPos = np.array([
            [self.gridCorner1[0],             self.gridCorner1[0] + boxLenX,   self.gridCorner1[1], self.gridCorner1[1] + boxLenY, 0],
            [self.gridCorner1[0] + boxLenX,   self.gridCorner1[0] + 2*boxLenX, self.gridCorner1[1], self.gridCorner1[1] + boxLenY, 1],
            [self.gridCorner1[0] + 2*boxLenX, self.gridCorner2[0],             self.gridCorner1[1], self.gridCorner1[1] + boxLenY, 2],

            [self.gridCorner1[0],             self.gridCorner1[0] + boxLenX,   self.gridCorner1[1] + boxLenY, self.gridCorner1[1] + 2*boxLenY, 3],
            [self.gridCorner1[0] + boxLenX,   self.gridCorner1[0] + 2*boxLenX, self.gridCorner1[1] + boxLenY, self.gridCorner1[1] + 2*boxLenY, 4],
            [self.gridCorner1[0] + 2*boxLenX, self.gridCorner2[0],             self.gridCorner1[1] + boxLenY, self.gridCorner1[1] + 2*boxLenY, 5],

            [self.gridCorner1[0],             self.gridCorner1[0] + boxLenX,   self.gridCorner1[1] + 2*boxLenY, self.gridCorner2[1], 6],
            [self.gridCorner1[0] + boxLenX,   self.gridCorner1[0] + 2*boxLenX, self.gridCorner1[1] + 2*boxLenY, self.gridCorner2[1], 7],
            [self.gridCorner1[0] + 2*boxLenX, self.gridCorner2[0],             self.gridCorner1[1] + 2*boxLenY, self.gridCorner2[1], 8]])
        
        #kondisi grid dalam bentuk array
        gridState = np.array([0, 0, 0, 0, 0, 0 ,0, 0, 0])

        #gambar posisi bidak player yang terdeteksi dan assign sebagai gerakan yang telah dibuat oleh player
        if circles is not None:
            circlesInt = np.round(circles[0, :]).astype("int")
            for (x, y, r) in circlesInt:
                cv.circle(self.drawnFrame, (x, y), r, (255, 0, 0), 2)
                for i in gridPos:
                    if i[0] <= x and x <= i[1] and i[2] <= y and y <= i[3] and gridState[int(i[4])] != 2:
                        gridState[int(i[4])] = 1
        
        #gambar posisi bidak bot dan assign sebagai gerakan yang telah dibuat oleh bot
        if self.botMoves is not None and self.gridCorner2[0] - self.gridCorner1[0] != 1:
            for i in self.botMoves:
                i = int(i)
                gridState[i] = 2
                if 0<= i <= 2:
                    cv.circle(self.drawnFrame, (int(self.gridCorner1[0] + boxLenX/2*(2*i+1)), int(self.gridCorner1[1] + boxLenY/2)), int(boxLenX/2 -10), (255, 0, 0), -1)
                elif 3 <= i <= 5:
                    cv.circle(self.drawnFrame, (int(self.gridCorner1[0] + boxLenX/2*(2*(i-3)+1)), int(self.gridCorner1[1] + boxLenY*3/2)), int(boxLenX/2 -10), (255, 0, 0), -1)
                elif 6 <= i <= 8:
                    cv.circle(self.drawnFrame, (int(self.gridCorner1[0] + boxLenX/2*(2*(i-6)+1)), int(self.gridCorner1[1] + boxLenY*5/2)), int(boxLenX/2 -10), (255, 0, 0), -1)

        #tunjukkan gambar utama dan juga gambar yang dilihat oleh komputer untuk keperluan kalibrasi
        cv.imshow("olel ngeri", processFrame)
        cv.imshow("ni olel", self.drawnFrame)
        
        #konversi kondisi grid dari bentuk array ke string
        msg = ''
        for i in gridState:
            msg += str(i)

        if cv.waitKey(1) == ord('x'):       #giliran selanjutnya
            return msg
        
        return 'zonk'

    #method publisher yang hanya mempublish apabila user telah memberi aba aba untuk berpindah gantian
    def timer_callback(self):
        msg = String()
        msg.data = self.readState()
        if msg.data != 'zonk':
            self.publisher_.publish(msg)
            print(msg.data)
            print('move sent, processing...')

    #method listener yang menerima perintah gerakan yang telah dikirim oleh node control dan menyimpannya
    def listener_callback(self, msg):
        self.get_logger().info('bot move to grid "%s"' % msg.data)
        self.botMoves =  np.append(self.botMoves, int(msg.data))
        
#fungsi main (duh)
def main(args=None):
    rclpy.init(args=args)

    visioner = VisionerTicTacToe()

    rclpy.spin(visioner)

    visioner.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()