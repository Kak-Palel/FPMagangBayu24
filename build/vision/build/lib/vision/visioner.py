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
        self.i = 0

        self.subscription = self.create_subscription(
            String,
            'ttt_moves',
            self.listener_callback,
            10)
        self.subscription

    def readState(self):
        # print("exec")
        success, rawFrame = self.cap.read()

        if not success:
            print("NDAK BISA BACA HUAAA")
            return
        
        drawnFrame = cv.rectangle(rawFrame, (150, 110), (490, 450), (255, 0, 0), 2)
        

        processFrame = cv.cvtColor(rawFrame, cv.COLOR_BGR2HSV)

        upper_range = np.array([15, 255, 255])
        lower_range = np.array([0, 50, 50])

        processFrame = cv.inRange(processFrame, lower_range, upper_range)
        processFrame = cv.GaussianBlur(processFrame, (9, 9), 2, 2)
        
        circles = cv.HoughCircles(processFrame, cv.HOUGH_GRADIENT, 1, 60, param1 = 90, param2 = 35, minRadius = 40, maxRadius = 0)
            
        if circles is not None:
            circlesInt = np.round(circles[0, :]).astype("int")
            for (x, y, r) in circlesInt:
                # if 140 <= x <= 500 and 100 <= y <= 460:
                cv.circle(drawnFrame, (x, y), r, (255, 0, 0), 2)
        # circles = np.array(np.around(circles))
        # circles = np.array(circles)

        # for circle in circles:
        # if circles is not None:
        #     for i in circles[0,:]:
        #         cv.circle(drawnFrame, (float(i[0]), float(i[1])), float(i[2]), (255, 0, 0), 2)


        
            

        cv.imshow("ni olel", drawnFrame)
        cv.imshow("olel ngeri", processFrame)
        cv.waitKey(1)

    def timer_callback(self):
        self.readState()

        msg = String()
        msg.data = 'SUSHI CANTIK: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1


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