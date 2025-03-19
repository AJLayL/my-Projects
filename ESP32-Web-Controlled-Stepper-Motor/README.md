# ESP32 Stepper Motor Web Server

## Description
This project demonstrates how to control a stepper motor using an ESP32 through a web interface. The ESP32 hosts a web server, allowing users to start and stop the motor using a simple HTML-based control panel.

## Features
- Control a stepper motor via a web interface.
- ESP32 connects to a Wi-Fi network and serves an interactive control page.
- Uses the ULN2003 motor driver.
- Handles HTTP requests for motor control commands.

## Components Required
- ESP32 Development Board
- 28BYJ-48 Stepper Motor
- ULN2003 Stepper Motor Driver
- Wi-Fi Network
- Connecting Wires

## Wiring Diagram
| ESP32 Pin | ULN2003 Driver |
|-----------|---------------|
| GPIO 19   | IN1          |
| GPIO 18   | IN2          |
| GPIO 5    | IN3          |
| GPIO 17   | IN4          |

## Installation
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) if not already installed.
2. Install the ESP32 Board support package in Arduino IDE.
3. Install the necessary libraries:
   - `WiFi.h` (Built-in for ESP32)
   - `Stepper.h` (Available in Arduino Library Manager)
4. Update the `secrets.h` file with your Wi-Fi credentials:
   ```cpp
   const char* ssid = "your_SSID";
   const char* password = "your_PASSWORD";
   ```
5. Upload the code to the ESP32.
6. Open the Serial Monitor to find the assigned IP address.
7. Access the web interface via a browser using the ESP32's IP address.

## Usage
1. Connect the ESP32 and stepper motor setup to power.
2. Open a web browser and navigate to `http://<ESP32_IP>`.
3. Click the "ON" button to rotate the motor counterclockwise.
4. Click the "OFF" button to rotate the motor clockwise.

## Notes
- Ensure that the ESP32 is connected to a stable Wi-Fi network.
- The web server runs on port 80.
- The timeout for HTTP requests is set to 2 seconds.

## License
This project is open-source and available under the MIT License.

