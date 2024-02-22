import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2 as cv
import numpy as np



class VisionerTicTacToe(Node):

    def __init__(self):
        super().__init__('VisionerTicTacToe')
        self.cap = cv.VideoCapture(0)
        if not self.cap.isOpened():
            print("HUAAAAAAAAAA RUSAAAAAAAAAAAK")
        self.publisher_ = self.create_publisher(String, 'ttt_state', 10)
        timer_period = 0.032  # seconds | 30 fps
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.subscription = self.create_subscription(
            String,
            'ttt_moves',
            self.listener_callback,
            10)
        self.subscription

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

        upper_range = np.array([15, 255, 255])
        lower_range = np.array([0, 50, 50])

        processFrame = cv.inRange(processFrame, lower_range, upper_range)
        processFrame = cv.GaussianBlur(processFrame, (9, 9), 2, 2)
        
        circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1, 60, param1 = 90, param2 = 35, minRadius = 40, maxRadius = 0)
            
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
        self.get_logger().info('I heard: "%s"' % msg.data)

def main(args=None):
    rclpy.init(args=args)

    visioner = VisionerTicTacToe()

    rclpy.spin(visioner)

    visioner.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()