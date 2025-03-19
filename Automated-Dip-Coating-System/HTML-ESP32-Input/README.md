# ESP32 Dip Coating Automation System

## Description
This project implements an ESP32-based web server for controlling and monitoring a dip coating process. Users can configure dipping height and speed, as well as record experimental data such as date, time, and coating thickness before and after dipping. The system features a Wi-Fi-enabled interface to facilitate easy setup and data collection.

## Features
- Web-based interface for configuring dipping height and speed.
- Data collection page for recording experimental results.
- Wi-Fi connectivity for remote access.
- Real-time LED indication based on dipping parameters.
- Automatic Wi-Fi reconnection.

## Hardware Requirements
- ESP32 development board
- Wi-Fi network
- LED (optional for visual indication)
- Power source for ESP32

## Installation
1. Clone or download this repository.
2. Open the project in the Arduino IDE.
3. Install the necessary libraries:
   - `WiFi.h`
   - `WebServer.h`
4. Replace `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD` in the code with your network credentials.
5. Connect the ESP32 board to your computer.
6. Select the correct board (`ESP32 Dev Module`) and port in the Arduino IDE.
7. Upload the code to the ESP32.

## Usage
1. Power on the ESP32 and wait for it to connect to Wi-Fi.
2. Open the Serial Monitor to view the assigned IP address.
3. Enter the IP address in a web browser to access the setup page.
4. Configure the dipping height and speed, then submit the values.
5. Navigate to the data collection page to record experimental results.
6. The system will process and store the submitted values while providing real-time feedback.

## API Endpoints
- `/` - Opens the setup page.
- `/data` - Opens the data collection page.
- `/submitSetup?height=<value>&speed=<value>` - Submits the dipping parameters.
- `/submitData?date=<value>&time=<value>&thicknessBefore=<value>&thicknessAfter=<value>` - Submits experimental data.

## Troubleshooting
- If the ESP32 does not connect to Wi-Fi, ensure the SSID and password are correct.
- If the web interface is not accessible, check the Serial Monitor for the correct IP address.
- Ensure the ESP32 is powered properly and the firmware is correctly uploaded.

## Future Improvements
- Store submitted data in a database for long-term tracking.
- Implement authentication for secure access.
- Expand the interface to support additional experimental parameters.

## License
This project is open-source and available under the MIT License.

