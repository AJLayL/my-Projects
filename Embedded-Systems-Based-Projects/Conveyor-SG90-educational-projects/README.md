# Automated Conveyor Belt System with Servo Control

## Description
This project is an Arduino-based conveyor belt automation system that utilizes a servo motor for control. The conveyor starts automatically upon boot and detects objects using multiple sensors. A potentiometer allows for speed adjustment, and a timer-based mechanism stops the conveyor when an object reaches the end.

## Features
- Automated conveyor belt control using a servo motor.
- Object detection using digital sensors.
- Adjustable speed using a potentiometer.
- Timed stopping mechanism for precise object placement.
- Serial monitoring for debugging.

## Components Used
- **Arduino Board**
- **Servo Motor** (connected to pin 9)
- **Digital Sensors** (connected to pins 2-5 and 10)
- **Potentiometer** (connected to A1)
- **Resistors** (if needed)
- **Power Supply**

## Pin Connections

| Pin  | Component               |
|------|-------------------------|
| 2    | Object Detection Sensor |
| 3    | Object Detection Sensor |
| 4    | Object Detection Sensor |
| 5    | Object Detection Sensor |
| 9    | Servo Motor (PWM Control) |
| 10   | Stop/Start Sensor |
| A1   | Potentiometer (Speed Control) |

## Installation & Setup
1. Connect the servo motor to pin 9.
2. Connect digital sensors to pins 2, 3, 4, 5, and 10 with pull-up resistors.
3. Connect a potentiometer to analog input A1.
4. Upload the provided code to an Arduino board.
5. Open the Serial Monitor at 9600 baud rate to debug sensor readings.

## Usage
- The conveyor starts automatically when powered.
- The potentiometer adjusts the conveyor speed.
- When an object is detected at the last sensor, the conveyor stops for a set duration.
- After the stop interval, the conveyor resumes operation.

## Future Improvements
- Implementing more advanced motor control techniques.
- Adding an LCD display for real-time speed monitoring.
- Wireless control via Bluetooth or WiFi.

## License
This project is open-source and can be modified for personal and commercial use.
