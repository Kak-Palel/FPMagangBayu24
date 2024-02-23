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

        cv.namedWindow("ni olel")                                           #window dibutuhkan supaya dapat menggunakan trackbar
        cv.createTrackbar('param1', 'ni olel', 100, 200, self.nothing)      #trackbar untuk kalibrasi threshold yang di pass ke canny edge detector
        cv.createTrackbar('param2', 'ni olel', 15, 200, self.nothing)       #trackbar untuk kalibrasi akurasi deteksi lingkaran terhadap kualitas cahaya
        
        #buka camera
        self.cap = cv.VideoCapture(0)
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
    
    """
    Method untuk membaca keadaan grid.
    karena method ini terpanggil 30 kali perdetik, maka method ini dapat membaca kamera, memproses, dan 
    menampilkannya ke layar. Hasil proses diubah kebentuk string agar lebih mudah untuk dikirim. Method
    ini me-return string yang telah di proses tadi apabila user menekan tombol "x" yang menandakan pergantian
    giliran.
    """
    def readState(self):
        #membaca frame kamera
        successOpenCam, drawnFrame = self.cap.read()
        if not successOpenCam:
            print("NDAK BISA BACA HUAAA")
            return
        
        #buat copy dari drawnFrame dengan nama processFrame yang akan kita gunakan untuk memproses
        processFrame = drawnFrame.copy()
        
        #gambar kotak untuk memudahkan user menemukan dimana seharusnya grid tictactoe diletakkan
        drawnFrame = cv.rectangle(drawnFrame, (150, 110), (490, 450), (255, 0, 0), 2)
        
        #menutupi area yang tidak perlu untuk menghindari deteksi lingkaran yang tidak diinginkan
        processFrame = cv.rectangle(processFrame, (0, 0), (150, 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (150, 0), (490, 110), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (490, 0), (640, 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (150, 450), (490, 480), (0, 0, 0), -1)

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
        
        pram1 = int(cv.getTrackbarPos('param1', 'ni olel')) #upper threshold yang di pass ke canny edge detector, sebagai parameter yang dapat diubah dari trackbar
        pram2 = int(cv.getTrackbarPos('param2', 'ni olel')) #tingkat akurasi deteksi lingkaran tergantung pada kualitas cahaya, sebagai parameter yang dapat diubah dari trackbar

        #deteksi lingkaran
        circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1, 60, param1 = pram1, param2 = pram2, minRadius = 40, maxRadius = 0)
            
        #batas batas tiap kolom di grid dan juga index kolomnya
        gridPos = np.array([
            [150, 263, 110, 223, 0],
            [264, 376, 110, 223, 1],
            [377, 490, 110, 223, 2],
            [150, 263, 224, 336, 3],
            [264, 376, 224, 336, 4],
            [377, 490, 224, 336, 5],
            [150, 263, 337, 450, 6],
            [264, 376, 337, 450, 7],
            [377, 490, 337, 450, 8]])
        
        #kondisi grid dalam bentuk array
        gridState = np.array([0, 0, 0, 0, 0, 0 ,0, 0, 0])

        #gambar posisi bidak player yang terdeteksi dan assign sebagai gerakan yang telah dibuat oleh player
        if circles is not None:
            circlesInt = np.round(circles[0, :]).astype("int")
            for (x, y, r) in circlesInt:
                cv.circle(drawnFrame, (x, y), r, (255, 0, 0), 2)
                for i in gridPos:
                    if i[0] <= x and x <= i[1] and i[2] <= y and y <= i[3] and gridState[i[4]] != 2:
                        gridState[i[4]] = 1
        
        #gambar posisi bidak bot dan assign sebagai gerakan yang telah dibuat oleh bot
        if self.botMoves is not None:
            for i in self.botMoves:
                i = int(i)
                gridState[i] = 2
                if 0<= i <= 2:
                    cv.circle(drawnFrame, (150 + 56*(2*i+1), 166), 50, (255, 0, 0), -1)
                elif 3 <= i <= 5:
                    cv.circle(drawnFrame, (150 + 56*(2*(i-3)+1), 278), 50, (255, 0, 0), -1)
                elif 6 <= i <= 8:
                    cv.circle(drawnFrame, (150 + 56*(2*(i-6)+1), 390), 50, (255, 0, 0), -1)

        #tunjukkan gambar utama dan juga gambar yang dilihat oleh komputer untuk keperluan kalibrasi
        cv.imshow("olel ngeri", processFrame)
        cv.imshow("ni olel", drawnFrame)
        
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