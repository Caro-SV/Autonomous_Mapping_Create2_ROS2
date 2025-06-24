# <p align="center">Create 2 + LIDAR + SLAM Toolbox + Teleoperación</p>

<p align="center">
  <i>Entorno ROS 2 configurado para realizar mapeo y navegación autónoma con el robot <b>Create 2</b> usando <code>slam_toolbox</code>, sensor LIDAR y teleoperación por teclado.</i>
</p>

---

## Requisitos Iniciales

- ROS 2 Humble instalado tanto en el PC como en el Create 2.
- Conexión de red entre el PC y el robot.
- Sensor LIDAR compatible (ej. RPLIDAR A1, A2).

---

## Conexión y Nodo Base
Lanzar el nodo bringup para conocer el estado del robot después de establecer la conexión.
```bash
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

> Nota: En caso de que el puerto no sea `ttyUSB0`, editar el archivo `rplidar.launch.py` para ajustar por el puerto correcto.

4. Ejecutar nodo del LIDAR:
```bash
ros2 launch rplidar_ros rplidar.launch.py
```

5. Visualización en Rviz:
```bash
ros2 launch rplidar_ros view_rplidar.launch.py
```
En la siguiente imagen se observa el robot create 2 con el lidar y la captura del mismo en Rviz.
<p align="center">
  <img src="https://github.com/user-attachments/assets/7aac8755-940b-402e-8435-499501eee820" alt="Vista de Rviz con LIDAR activo" width="700">
</p>

---

##  SLAM Toolbox (en PC)

1. Ejecutar SLAM Toolbox luego del nodo bringup y del LIDAR:
```bash
ros2 launch slam_toolbox online_async_launch.py
```

2. Mover el robot usando teleoperación para generar el mapa.
```bash
ros2 run modelo_create teleopkey
```

3. Guardar el mapa creado:
```bash
ros2 run nav2_map_server map_saver -f /ruta/mapa_guardado
```
---

## Teleoperación por Teclado

Se incluye un nodo en Python que permite controlar el robot usando las teclas `W/A/S/D`. El nodo publica directamente en `/cmd_vel`.

### Controles:

- **w** → Avanzar  
- **s** → Retroceder  
- **a** → Girar izquierda  
- **d** → Girar derecha  
- **Espacio** → Detener  
- **q** → Salir

> Este nodo fue desarrollado sobre ROS2 y está incluido en `teleopkey.py`.

---

## 📚 Repositorios Utilizados

Se utilizaron y adaptaron los siguientes repositorios como base:

- 🔗 [babakhani/rplidar_ros2](https://github.com/babakhani/rplidar_ros2) — (modificado y renombrado)
- 🔗 [SteveMacenski/slam_toolbox](https://github.com/SteveMacenski/slam_toolbox)

---
