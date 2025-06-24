# <p align="center">Create 2 + LIDAR + SLAM Toolbox + Teleoperación</p>

<p align="center">
  <i>Repositorio con todo el entorno ROS 2 configurado para realizar mapeo y navegación autónoma con el robot <b>Create 2</b> usando <code>slam_toolbox</code>, sensor LIDAR y teleoperación por teclado.</i>
</p>

---

## Requisitos Iniciales

- ROS 2 Humble instalado tanto en el PC como en el Create 2.
- Conexión de red entre el PC y el robot.
- Sensor LIDAR compatible (ej. RPLIDAR A1, A2).

---

## Conexión y Nodo Base

```bash
# Lanzar el nodo bringup para conocer el estado del robot después de establecer la conexión
ros2 launch create_bringup create_2.launch
```

---

## Configuración del LIDAR (en Create 2)

1. Verificar puerto USB en el que se conecta el sensor LIDAR:
```bash
ls /dev/ttyUSB*
```

2. Dar permisos al puerto:
```bash
sudo chmod 666 /dev/ttyUSB0
sudo usermod -aG dialout $USER
```

3. Verificar conexión:
```bash
lsusb
```

> Nota: En caso de que el puerto no sea `ttyUSB0`, editar el archivo `rplidar.launch.py` para usar el puerto correcto.

4. Ejecutar nodo del LIDAR:
```bash
ros2 launch rplidar_ros rplidar.launch.py
```

5. Visualización en Rviz:
```bash
ros2 launch rplidar_ros view_rplidar.launch.py
```

<p align="center">
  <img src="rviz_lidar_example.png" alt="Vista de Rviz con LIDAR activo" width="700">
</p>

---

##  SLAM Toolbox (en PC)

1. El sensor LIDAR se agregó al URDF del robot y se enlazó al `base_link`.

2. Ejecutar SLAM Toolbox luego del nodo bringup y del LIDAR:
```bash
ros2 launch slam_toolbox online_async_launch.py
```

3. Mover el robot usando teleoperación para generar el mapa. Luego, guardar el resultado:
```bash
ros2 run nav2_map_server map_saver -f /ruta/mapa_guardado
```

<p align="center">
  <img src="slam_map_example.png" alt="Mapa generado por SLAM Toolbox" width="700">
</p>

---

## 🎮 Teleoperación por Teclado

Se incluye un nodo en Python que permite controlar el robot usando las teclas `W/A/S/D`. El nodo publica directamente en `/cmd_vel`.

### Controles:

- **w** → avanzar  
- **s** → retroceder  
- **a** → girar izquierda  
- **d** → girar derecha  
- **espacio** → detener  
- **q** → salir

> Este nodo fue desarrollado sobre ROS2 y está incluido en `teleop_keyboard.py`.

---

## 📚 Repositorios Utilizados

Se utilizaron y adaptaron los siguientes repositorios como base:

- 🔗 [babakhani/rplidar_ros2](https://github.com/babakhani/rplidar_ros2) — (modificado y renombrado)
- 🔗 [SteveMacenski/slam_toolbox](https://github.com/SteveMacenski/slam_toolbox)

---
