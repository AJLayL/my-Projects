# Home Environment Control using ESP32

## Project Overview
This project is an **educational home automation system** using **ESP32**. It integrates various sensors to monitor **temperature, humidity, light intensity, and motion** while controlling a **fan, LED, and motor** based on environmental conditions. The system also includes an **OLED display** for real-time data visualization and user interaction via a rotary encoder.

## Features
- ✅ **Automatic Fan Control** – Turns **ON/OFF** based on temperature.
- ✅ **Automatic LED Control** – Activates in **low-light conditions**.
- ✅ **Gyroscope-based Speed Control** – Adjusts **fan and LED brightness** using motion data.
- ✅ **OLED Display** – Shows **real-time sensor readings** with a **scrollable menu**.
- ✅ **User Inputs** – Buttons and a rotary encoder for manual control.
- ✅ **Serial Monitoring** – Logs **sensor values & device status** for debugging.

---

## Hardware Components
### Sensors & Inputs
- 🔹 **DHT22** – Measures **temperature** and **humidity**.
- 🔹 **LDR (Light Dependent Resistor)** – Detects **ambient light levels**.
- 🔹 **MPU6050** – Provides **accelerometer & gyroscope data**.
- 🔹 **Potentiometer** – Adjusts **PWM output**.
- 🔹 **Rotary Encoder (Knob)** – Selects **sensor data display**.
- 🔹 **Push Buttons** – **Manually control** the **LED & motor**.

### Outputs & Actuators
- 🔹 **LED** – Controlled based on **ambient light levels**.
- 🔹 **DC Motor** – Acts as a **fan**, controlled by **temperature & user input**.
- 🔹 **OLED Display (128x64)** – Displays real-time data.

---

## Software & Libraries
### Microcontroller
- **ESP32** – Used for processing sensor data and controlling outputs.

### Required Libraries
- `Adafruit_GFX.h` – Graphics library for OLED.
- `Adafruit_SSD1306.h` – OLED display driver.
- `DHT.h` – Library for DHT22 sensor.
- `Wire.h` – I2C communication for MPU6050.
- `MPU6050.h` – Gyroscope and accelerometer library.

---

## Installation & Setup
### 1. **Install Arduino IDE & ESP32 Board Support**
- Download & install [Arduino IDE](https://www.arduino.cc/en/software).
- Add **ESP32 board support** via **Boards Manager**.

### 2. **Connect Components**
Wire the components to the ESP32 according to the **circuit diagram**.

### 3. **Upload the Code**
- Open the provided `.ino` file in Arduino IDE.
- Select **ESP32 Dev Module** as the board.
- Upload the code and monitor via **Serial Monitor**.

---

## Usage Instructions
1. **Power ON** the ESP32.
2. The **OLED display** will show real-time sensor data.
3. Adjust fan speed using **MPU6050 tilt angle**.
4. Use the **rotary encoder** to switch between displayed sensor data.
5. The **LED and fan** will respond automatically based on sensor readings.
6. Monitor live data via **Serial Monitor**.

---

## Future Improvements
- 📌 Add **Wi-Fi & MQTT** for remote control.
- 📌 Implement **Blynk** or **ESPHome** for mobile app integration.
- 📌 Introduce **voice control** using Google Assistant.

---

## License
This project is open-source and available under the **MIT License**.

---

