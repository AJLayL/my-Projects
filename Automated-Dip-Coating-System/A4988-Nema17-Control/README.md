# ESP32 Dip Coating Machine - Step Control

## 📌 Project Overview  
This project provides an **automated dip coating system** controlled by an **ESP32**. The system translates stepper motor movements into height adjustments, allowing precise dip coating operations.  

## 🔧 Features  
- **Motor Control:** Uses stepper motor to adjust dip height and speed.  
- **Limit Switches:** Detects upper and lower limits for positioning.  
- **Step Calculation:** Converts height to steps for accuracy.  
- **Automated Dipping:** Moves to desired height and performs dipping action.  

## 📂 Hardware Requirements  
- ESP32 microcontroller  
- Stepper motor (compatible with ESP32)  
- Motor driver module  
- Limit switches (Upper and Lower)  
- Power supply  

## 🔌 Wiring Diagram  
| Component    | ESP32 Pin |
|-------------|----------|
| Step Pin    | GPIO 2   |
| Dir Pin     | GPIO 0   |
| Upper Limit | GPIO 16  |
| Lower Limit | GPIO 17  |

## 🚀 Installation  
1. **Connect hardware components** as per the wiring diagram.  
2. **Install Arduino IDE** and add ESP32 board support.  
3. **Upload the code** to the ESP32 using Arduino IDE.  

## 📜 Code Explanation  
- **`moveMotor()`** - Controls the stepper motor movement.  
- **`gotoLowerLimit()`** - Moves the motor downward until the lower limit is reached.  
- **`countStep()`** - Counts the steps taken until the upper limit.  
- **`desiredStepEquation()`** - Calculates the required steps for a given height.  
- **`gotoDesiredStep()`** - Moves the motor to the target height.  
- **`startDipProcess()`** - Manages the dipping operation.  

## 🛠️ Usage  
1. Press the **start button** to initialize the dip coating process.  
2. The system **moves to the lower limit** and counts steps.  
3. Once calibrated, it **moves to the desired height** for coating.  
4. The **dipping process starts** and retracts after completion.  

## ⚠️ Known Issues & Fixes  
- **Syntax Errors:**  
  - Missing `;` in `gotoDesiredStep()`.  
  - Incorrect `switch(button):` usage (should be `switch(button) { case 1: ... }`).  
- **Logic Bugs:**  
  - `if(lowerLimit && loweringState)` should use `digitalRead(lowerLimit) == HIGH` for proper condition checking.  

## 📌 Future Improvements  
- Implement real-time **speed control** via user input.  
- Add **OLED display support** for live status updates.  
- Use **PID control** for smoother movement.  

---

## 📝 License  
This project is licensed under the **MIT License**. Feel free to use and modify it.  

## 🤝 Contributing  
Pull requests and improvements are welcome!  
