<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <title>Create 2 SLAM Toolbox + Teleoperación</title>
  <style>
    body {
      font-family: 'Courier New', Courier, monospace;
      background-color: #1e1e1e;
      color: #d4d4d4;
      padding: 40px;
      line-height: 1.6;
    }
    h1, h2, h3 {
      color: #569cd6;
    }
    code {
      background-color: #2d2d2d;
      padding: 2px 6px;
      border-radius: 4px;
      font-size: 0.95em;
      color: #c586c0;
    }
    pre {
      background-color: #2d2d2d;
      padding: 10px;
      border-left: 4px solid #007acc;
      overflow-x: auto;
      color: #dcdcaa;
    }
    a {
      color: #4fc1ff;
      text-decoration: none;
    }
    a:hover {
      text-decoration: underline;
    }
    .section {
      margin-bottom: 40px;
    }
    .centered-img {
      display: block;
      margin: 20px auto;
      max-width: 90%;
      border: 2px solid #444;
      border-radius: 8px;
    }
  </style>
</head>
<body>
  <h1>🧠 Create 2 + LIDAR + SLAM Toolbox + Teleoperación</h1>
  <p>Repositorio con todo el entorno ROS 2 configurado para realizar mapeo y navegación autónoma con el robot <strong>Create 2</strong> usando <code>slam_toolbox</code>, sensor LIDAR y teleoperación por teclado.</p>

  <div class="section">
    <h2>Requisitos iniciales</h2>
    <ul>
      <li>ROS 2 Humble instalado tanto en el PC como en el Create 2.</li>
      <li>Conexión de red entre el PC y el robot.</li>
      <li>Sensor LIDAR compatible (ej. RPLIDAR A1, A2).</li>
    </ul>
  </div>

  <div class="section">
    <h2>Conexión y nodo base</h2>
    <pre><code>Lanzar el nodo bringup para conecer el estado del robot después de establecer la conexión
ros2 launch create_bringup create_2.launch</code></pre>
  </div>

  <div class="section">
    <h2>Configuración del LIDAR (en Create 2)</h2>
    <ol>
      <li>Verificar puerto USB en el que se conecta el sensor Lidar:</li>
      <pre><code>ls /dev/ttyUSB*</code></pre>

      <li>Dar permisos al puerto:</li>
      <pre><code>sudo chmod 666 /dev/ttyUSB0
sudo usermod -aG dialout $USER</code></pre>

      <li>Verificar conexión:</li>
      <pre><code>lsusb</code></pre>

      <li>Nota: En caso de que el puerto no sea ttyUSB0, entonces editar el archivo <code>rplidar.launch.py</code> para usar el puerto correcto.</li>

      <li>Ejecutar nodo del LIDAR:</li>
      <pre><code>ros2 launch rplidar_ros rplidar.launch.py</code></pre>

      <li>Visualización en Rviz:</li>
      <pre><code>ros2 launch rplidar_ros view_rplidar.launch.py</code></pre>

      <img src="rviz_lidar_example.png" alt="Vista de Rviz con LIDAR activo" class="centered-img">
    </ol>
  </div>

  <div class="section">
    <h2>SLAM Toolbox (en PC)</h2>
    <ol>
      <li>Para este proyecto se agregó el LIDAR al URDF del robot y enlazado al <code>base_link</code>.</li>

      <li>Después de correr el nodo bringup y el nodo del lidar, ejecutar SLAM Toolbox:</li>
      <pre><code>ros2 launch slam_toolbox online_async_launch.py</code></pre>

      <li>Mover el robot con el nodo de teleoperación para crear un mapa del entorno, luego en otra terminal guardar el mapa:</li>
      <pre><code>ros2 run nav2_map_server map_saver -f /ruta/mapa_guardado</code></pre>

      <img src="slam_map_example.png" alt="Mapa generado por SLAM Toolbox" class="centered-img">
    </ol>
  </div>

  <div class="section">
    <h2>Teleoperación por Teclado</h2>
    <p>Se incluye un nodo en Python que permite controlar el robot usando las teclas <code>W/A/S/D</code>. El nodo publica directamente en <code>/cmd_vel</code>.</p>

    <h3>Controles:</h3>
    <ul>
      <li><strong>w</strong> → avanzar</li>
      <li><strong>s</strong> → retroceder</li>
      <li><strong>a</strong> → girar izquierda</li>
      <li><strong>d</strong> → girar derecha</li>
      <li><strong>espacio</strong> → detener</li>
      <li><strong>q</strong> → salir</li>
    </ul>

    <p>Este nodo fue desarrollado sobre ROS2 y está incluido en <code>teleop_keyboard.py</code>.</p>
  </div>

  <div class="section">
    <h2>Repositorios Utilizados</h2>
    <li>Para la creación de este proyecto se utilizó como base los siguientes repositorios que fueron adaptados a las necesidades de este proyecto.</li>
    <ul>
      <li>LIDAR: <a href="https://github.com/babakhani/rplidar_ros2" target="_blank">babakhani/rplidar_ros2</a> (modificado y renombrado)</li>
      <li>SLAM: <a href="https://github.com/SteveMacenski/slam_toolbox" target="_blank">SteveMacenski/slam_toolbox</a></li>
    </ul>
  </div>
</body>
</html>
