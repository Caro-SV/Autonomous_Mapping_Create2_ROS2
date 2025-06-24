import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import termios
import tty

class TeleopKeyboard(Node):
    def __init__(self):
        super().__init__('teleopkey')
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.get_logger().info('Control con teclado: w/s = adelante/atrás, a/d = izquierda/derecha, q = salir')
        self.run()

    def get_key(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            key = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return key

    def run(self):
        try:
            while rclpy.ok():
                key = self.get_key()
                twist = Twist()

                if key == 'w':
                    twist.linear.x = 0.2
                elif key == 's':
                    twist.linear.x = -0.2
                elif key == 'a':
                    twist.angular.z = 1.0
                elif key == 'd':
                    twist.angular.z = -1.0
                elif key == ' ':
                    twist.linear.x = 0.0
                    twist.angular.z = 0.0
                elif key == 'q':
                    break

                self.publisher.publish(twist)

        except KeyboardInterrupt:
            pass

def main(args=None):
    rclpy.init(args=args)
    node = TeleopKeyboard()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
