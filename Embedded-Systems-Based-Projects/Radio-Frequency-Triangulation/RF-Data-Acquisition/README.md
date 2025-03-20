# Kalman Filter for Sensor Data  

## 📌 Overview  
This project implements a **Kalman Filter** to process RF signal strength readings from two sensors. The goal is to reduce noise and improve distance estimation.  

## 🛠 Features  
- **Kalman Filtering**: Smooths out sensor noise for more accurate readings.  
- **Analog Signal Processing**: Reads RF signal strength from two analog inputs.  
- **Distance Calculation**: Converts filtered values into distance estimates.  

## 🔧 Hardware Requirements  
- Microcontroller (ESP32, Arduino, etc.)  
- Two RF signal strength sensors (connected to A1 & A2)  

## 📜 Code Explanation  
The main processing steps include:  
1. **Reading Raw Sensor Data**:  
   - Analog inputs **A1** and **A2** receive RF strength values.  
2. **Applying Kalman Filter**:  
   - Estimates the true voltage by minimizing noise.  
3. **Distance Calculation**:  
   - Uses predefined calibration values (`M1, C1, M2, C2`) to map readings to distances.  

## 🚀 Getting Started  
1. **Clone the Repository**:  
   ```sh
   git clone https://github.com/YourUsername/kalman-filter-sensor.git
   cd kalman-filter-sensor
2. Upload the Code to your microcontroller using the Arduino IDE.
3. Open Serial Monitor (9600 baud) to view the filtered distance outputs.

## 🏗 Future Improvements
- Implement adaptive Kalman gain tuning.
- Test with different sensor types.
- Optimize computational efficiency.

## 📜 License
This project is open-source under the MIT License.