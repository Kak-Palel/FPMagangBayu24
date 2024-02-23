import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2 as cv
import numpy as np



class VisionerTicTacToe(Node):

    def __init__(self):
        super().__init__('VisionerTicTacToe')

        cv.namedWindow("ni olel")
        cv.createTrackbar('param1', 'ni olel', 100, 200, self.nothing)
        cv.createTrackbar('param2', 'ni olel', 15, 200, self.nothing)
        self.cap = cv.VideoCapture(0)
        if not self.cap.isOpened():
            print("HUAAAAAAAAAA RUSAAAAAAAAAAAK")

        self.botMoves = np.array([])
        
        self.publisher_ = self.create_publisher(String, 'ttt_state', 10)
        timer_period = 0.032  # seconds | 30 fps
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.subscription = self.create_subscription(
            String,
            'ttt_moves',
            self.listener_callback,
            10)
        self.subscription
        print("constructor excuted")

    def nothing(self):
        pass
    
    def readState(self):
        
        successOpenCam, drawnFrame = self.cap.read()

        if not successOpenCam:
            print("NDAK BISA BACA HUAAA")
            return
        
        processFrame = drawnFrame.copy()
        
        drawnFrame = cv.rectangle(drawnFrame, (150, 110), (490, 450), (255, 0, 0), 2)
        
        processFrame = cv.rectangle(processFrame, (0, 0), (150, 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (150, 0), (490, 110), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (490, 0), (640, 480), (0, 0, 0), -1)
        processFrame = cv.rectangle(processFrame, (150, 450), (490, 480), (0, 0, 0), -1)
        processFrame = cv.cvtColor(processFrame, cv.COLOR_BGR2HSV)

        # processFrame = cv.GaussianBlur(processFrame, (5, 5), 2, 2)
        # processFrame = cv.blur(processFrame, (5,5))
        processFrame = cv.medianBlur(processFrame, 5)
        # processFrame = cv.bilateralFilter(processFrame, 15, 100, 100)

        mask1 = processFrame.copy()
        mask2 = processFrame.copy()
        
        upper_range = np.array([15, 255, 255])
        lower_range = np.array([0, 100, 100])

        mask1 = cv.inRange(mask1, lower_range, upper_range)

        upper_range = np.array([179, 255, 255])
        lower_range = np.array([155, 100, 100])

        mask2 = cv.inRange(mask2, lower_range, upper_range)

        processFrame = mask1 + mask2
        
        pram1 = int(cv.getTrackbarPos('param1', 'ni olel'))
        pram2 = int(cv.getTrackbarPos('param2', 'ni olel'))

        # circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1.4, 50)
        circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1, 60, param1 = pram1, param2 = pram2, minRadius = 40, maxRadius = 0)
            
        gridPos = np.array([
            [150, 263, 110, 223, 1],
            [264, 376, 110, 223, 2],
            [377, 490, 110, 223, 3],
            [150, 263, 224, 336, 4],
            [264, 376, 224, 336, 5],
            [377, 490, 224, 336, 6],
            [150, 263, 337, 450, 7],
            [264, 376, 337, 450, 8],
            [377, 490, 337, 450, 9]])
        
        gridState = np.array([0, 0, 0, 0, 0, 0 ,0, 0, 0])

        if circles is not None:
            circlesInt = np.round(circles[0, :]).astype("int")
            for (x, y, r) in circlesInt:
                cv.circle(drawnFrame, (x, y), r, (255, 0, 0), 2)
                for i in gridPos:
                    if i[0] <= x and x <= i[1] and i[2] <= y and y <= i[3] and gridState[i[4]-1] != 2:
                        gridState[i[4]-1] = 1
        
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


        cv.imshow("olel ngeri", processFrame)
        cv.imshow("ni olel", drawnFrame)
        
        msg = ''
        for i in gridState:
            msg += str(i)

        if cv.waitKey(1) == ord('x'):
            return msg
        else:
            return 'zonk'

    def timer_callback(self):
        

        msg = String()
        msg.data = self.readState()
        if msg.data != 'zonk':
            self.publisher_.publish(msg)
            print(msg.data)
            print('move sent, processing...')

    def listener_callback(self, msg):
        self.get_logger().info('bot move to grid "%s"' % msg.data)
        self.botMoves =  np.append(self.botMoves, int(msg.data))
        

def main(args=None):
    rclpy.init(args=args)

    visioner = VisionerTicTacToe()

    rclpy.spin(visioner)

    visioner.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()