# ESP32 Web Server Servo Control  

## **Overview**  
This project enables control of a servo motor through a web-based interface hosted by an ESP32. Users can adjust the servo position using a slider on the web page.

## **Features**  
- Web interface for controlling servo position  
- Real-time updates using AJAX  
- Wi-Fi connectivity with ESP32  

## **Requirements**  
- ESP32 development board  
- Servo motor  
- Wi-Fi credentials (stored in `secrets.h`)  
- Arduino IDE with ESP32 libraries installed  

## **Installation & Setup**  
1. **Install Required Libraries**:  
   - `WiFi.h` for network connectivity  
   - `ESP32Servo.h` for servo control  

2. **Prepare the Code**:  
   - Update Wi-Fi credentials in `secrets.h`  
   - Upload the code to the ESP32 using Arduino IDE  

3. **Run the Web Server**:  
   - Connect to the ESP32’s IP address displayed in the Serial Monitor  
   - Use the web interface to control the servo  

## **Usage**  
- Move the slider to adjust the servo position in real-time  
- The ESP32 processes HTTP GET requests to set the servo angle  

## **Code Structure**  
- `setup()`: Initializes Wi-Fi and attaches the servo  
- `loop()`: Listens for client requests and updates servo position accordingly  

## **License**  
This project is open-source and free to use.
