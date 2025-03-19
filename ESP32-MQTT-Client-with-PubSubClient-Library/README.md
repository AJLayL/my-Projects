ESP32 MQTT Client with PubSubClient
Overview
This ESP32-based project connects to a WiFi network and an MQTT broker, allowing message publishing and subscription using the PubSubClient library. It is useful for IoT applications where ESP32 needs to communicate with other devices or cloud services via MQTT.

Features
✅ Connects ESP32 to WiFi and an MQTT broker
✅ Subscribes to an MQTT topic and processes incoming messages
✅ Publishes messages to a specified MQTT topic
✅ Automatic reconnection in case of disconnection

Hardware Requirements
ESP32 development board
WiFi network access
MQTT broker (e.g., EMQX, Mosquitto, HiveMQ)
Software Requirements
Arduino IDE (or PlatformIO)
ESP32 board package (Install via Arduino Boards Manager)
PubSubClient library (Install via Arduino Library Manager)
Installation & Setup
1. Install Arduino IDE and ESP32 Board Support
Follow the instructions here: ESP32 Arduino Setup

2. Install Required Libraries
In Arduino IDE, go to Sketch → Include Library → Manage Libraries and install:

PubSubClient
WiFi (comes preinstalled)
3. Configure WiFi and MQTT Broker Credentials
Modify secrets.h or uncomment and replace placeholders in the code:
```cpp
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* mqtt_broker = "your_broker_address";
const char* mqtt_topic = "your_mqtt_topic";
const char* mqtt_username = "your_mqtt_username";
const char* mqtt_password = "your_mqtt_password";
const int mqtt_port = 8883; // Secure MQTT port (Use 1883 for non-TLS)
```
4. Upload Code to ESP32
Connect ESP32 to your computer via USB.
Select the correct Board (ESP32 Dev Module) and Port in Arduino IDE.
Click Upload and open the Serial Monitor (115200 baud) to check logs.
Usage
ESP32 connects to WiFi and an MQTT broker.
It subscribes to the specified topic and listens for incoming messages.
Upon a successful connection, it publishes a greeting message:
Hi EMQX I'm ESP32 ^^
The ESP32 continuously publishes a test message:
Hello! =3
Received messages are displayed in the Serial Monitor.

Troubleshooting
Ensure your MQTT broker is running and accessible.
Check WiFi credentials and broker settings.
If using a secure MQTT connection (TLS), configure certificates if required.
License
This project is licensed under the MIT License.