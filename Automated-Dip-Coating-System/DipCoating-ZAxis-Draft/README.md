# Dip Coating Automation System with ESP32

## Project Overview
This project is an ESP32-based automated dip coating system designed for precise and controlled dipping of materials into a solution. The system utilizes stepper motors for movement, limit switches for calibration, and a web-based interface for user input and data logging. The goal is to create a cost-effective and accessible dip coating automation system, particularly for medical implants.

## Features
- **WiFi Connectivity**: The ESP32 hosts a web server for remote control.
- **Web Interface**: Users can configure dipping height, speed, and collect coating data.
- **Stepper Motor Control**: Moves the dipping platform with precision.
- **Limit Switches**: Used for calibration to determine movement range.
- **Data Logging**: Records parameters such as coating thickness before and after dipping.
- **Error Handling**: Ensures safe operation with boundary conditions.

## Installation and Setup
### Hardware Requirements
- ESP32 microcontroller
- Stepper motor and driver (A4988 or DRV8825)
- Limit switches (Upper and Lower)
- Push buttons for calibration and start
- LED indicators
- Power supply (12V or as required by motor)

### Software Requirements
- Arduino IDE
- ESP32 Board Package installed in Arduino IDE
- Required libraries:
  - `WiFi.h`
  - `WebServer.h`

### Wiring
1. Connect the stepper motor to the ESP32 (DIR and STEP pins).
2. Wire the limit switches to designated GPIOs.
3. Connect buttons for starting dipping and calibration.
4. Attach LEDs for status indication.

### Code Setup
1. Clone this repository or copy the code into Arduino IDE.
2. Update `ssid` and `password` variables with your WiFi credentials.
3. Upload the code to the ESP32 using Arduino IDE.
4. Open the Serial Monitor to verify the connection and IP address.

## Usage
1. **Connect to WiFi**: The ESP32 will start as a web server.
2. **Access the Web Interface**: Open the ESP32's IP address in a browser.
3. **Set Dipping Parameters**: Enter the desired dipping height and speed.
4. **Start Dipping Process**: Press the start button, and the system will execute the dipping sequence.
5. **Monitor and Record Data**: The system will log thickness measurements and display them on the web interface.

## Troubleshooting
- **ESP32 Not Connecting to WiFi**: Check SSID/password and ensure the router is active.
- **Stepper Motor Not Moving**: Verify wiring and stepper driver connections.
- **Limit Switches Not Detected**: Ensure proper wiring and pin assignments.
- **Web Interface Not Loading**: Ensure ESP32 is connected to the network and check the Serial Monitor for the IP address.

## Future Improvements
- Implement IoT capabilities for remote monitoring.
- Add a touchscreen interface for local control.
- Enhance error handling and logging mechanisms.

## License
This project is open-source and available for modification and improvement.

