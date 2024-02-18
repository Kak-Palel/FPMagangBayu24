import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2 as cv

class VisionerTicTacToe(Node):

    def __init__(self):
        super().__init__('VisionerTicTacToe')
        self.publisher_ = self.create_publisher(String, 'ttt_state', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

        self.subscription = self.create_subscription(
            String,
            'ttt_moves',
            self.listener_callback,
            10)
        self.subscription

    def timer_callback(self):
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

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    visioner.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()