import rclpy                      # Cliente de ROS2 en Python
from rclpy.node import Node       # Clase base para todos los nodos de ROS2
from geometry_msgs.msg import Twist  # Mensaje de tipo Twist para mover el robot
import sys                        # Acceso al sistema (para entrada de teclado)
import termios                    # Configuración de terminal Unix
import tty                        # Modo raw para leer teclas

class TeleopKeyboard(Node):
    def __init__(self):
        super().__init__('teleopkey')  # Inicializa el nodo con nombre 'teleopkey'
        
        # Crea un publicador para el tópico 'cmd_vel' que publica mensajes Twist (velocidades)
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        
        # Muestra instrucciones básicas en la consola
        self.get_logger().info('Control con teclado: w/s = adelante/atrás, a/d = izquierda/derecha, q = salir')
        
        self.run()  # Inicia el bucle principal de control por teclado

    def get_key(self):
        """
        Captura una tecla del teclado sin necesidad de presionar Enter.
        Usa configuración en modo raw para lectura inmediata.
        """
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)  # Guarda configuración anterior del terminal
        try:
            tty.setraw(sys.stdin.fileno())   # Cambia a modo raw
            key = sys.stdin.read(1)          # Lee un solo carácter
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)  # Restaura configuración
        return key

    def run(self):
        """
        Bucle principal que escucha teclas y publica comandos de movimiento en 'cmd_vel'.
        """
        try:
            while rclpy.ok():
                key = self.get_key()         # Captura tecla presionada
                twist = Twist()              # Crea un mensaje de tipo Twist

                # Mapear teclas a movimientos
                if key == 'w':
                    twist.linear.x = 0.2     # Avanzar
                elif key == 's':
                    twist.linear.x = -0.2    # Retroceder
                elif key == 'a':
                    twist.angular.z = 1.0    # Girar izquierda
                elif key == 'd':
                    twist.angular.z = -1.0   # Girar derecha
                elif key == ' ':             # Espacio: detener
                    twist.linear.x = 0.0
                    twist.angular.z = 0.0
                elif key == 'q':             # Salir del programa
                    break

                self.publisher.publish(twist)  # Publica el comando en el tópico

        except KeyboardInterrupt:
            pass  # Permite salir limpiamente con Ctrl+C

def main(args=None):
    """
    Función principal para iniciar y cerrar el nodo de forma segura.
    """
    rclpy.init(args=args)
    node = TeleopKeyboard()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()