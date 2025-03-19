# Raspberry Pi Servo Control for Camera Positioning

## Description
This project controls two servos using a Raspberry Pi and an Adafruit PCA9685 servo driver. The servos adjust the position of a camera (not yet installed), with one servo controlling the **X-axis (left/right movement)** and the other controlling the **Y-axis (up/down movement)**. 

Users input angles to move the servos, allowing manual control of camera positioning.

## Features
- Controls **two servos** for X and Y movement.
- Uses an **Adafruit PCA9685 PWM driver** for precision.
- Accepts **user input** for real-time servo angle adjustments.
- Outputs **debug information** to track servo movements.

## Components Used
- **Raspberry Pi** (Any model with I2C support)
- **Adafruit PCA9685 PWM Servo Driver**
- **Two Servo Motors** (For X and Y movement)
- **Jumper Wires**
- **Power Supply** (5V for servos)

## Pin Connections

| Raspberry Pi GPIO | Component                  |
|------------------|---------------------------|
| SDA (GPIO 2)    | Adafruit PCA9685 SDA       |
| SCL (GPIO 3)    | Adafruit PCA9685 SCL       |
| 5V              | Power for PCA9685          |
| GND             | Ground                     |
| PCA9685 Channel 1 | Servo for Y-axis (Head movement) |
| PCA9685 Channel 2 | Servo for X-axis (Body movement) |

## Installation & Setup
1. **Enable I2C on Raspberry Pi**:  
   Run `sudo raspi-config`, navigate to **Interfacing Options**, and enable **I2C**.
   
2. **Install required Python libraries**:
   ```bash
   sudo apt update
   sudo apt install python3-pip
   pip3 install adafruit-circuitpython-pca9685 RPi.GPIO
    ```
3. Wire the components as shown in the pin connection table.

4. Run the script:
    ```
    python3 servo_control.py
    ```
## Usage
**The script will prompt for servo angles:**
- Head Servo (Y-axis): Enter 0° (up) to 180° (down).
- Body Servo (X-axis): Enter 0° (right) to 180° (left).
- The servos will move to the specified angles.
- Press Ctrl+C to exit.

## Future Improvements
- Add a camera module for real-time vision tracking.
- Implement automatic tracking using OpenCV.
- Add a web interface for remote servo control.