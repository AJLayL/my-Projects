# Dip Coating Machine - Initialization Phase

## Overview
This project initializes the ESP32-based dip coating machine by determining the step-to-height ratio of the stepper motor. The code calculates the maximum step count for the full range of motion and translates desired height values into stepper motor movements.

## Features
- Detects upper and lower limit switches to measure the full range of motion.
- Calculates the step-to-height ratio for precise positioning.
- Moves the stepper motor to a specified height using calculated step values.

## Hardware Requirements
- ESP32
- Stepper motor (e.g., NEMA 17)
- Motor driver
- Limit switches (upper and lower)
- Power supply

## Pin Configuration
| Pin | Function |
|------|-----------|
| GPIO 0  | Direction Control |
| GPIO 2  | Step Control |
| GPIO 16 | Upper Limit Switch |
| GPIO 17 | Lower Limit Switch |

## Installation & Setup
1. Connect the ESP32 to the stepper motor driver and limit switches as per the pin configuration.
2. Upload the code to the ESP32 using Arduino IDE.
3. Set the `maxHeight` variable by manually measuring the distance between the upper and lower limits.
4. Power on the system and allow the stepper motor to move to the lower limit for calibration.

## How It Works
1. The system moves the stepper motor downwards until the lower limit switch is triggered, counting the steps required.
2. The total steps (`maxStep`) are stored to determine the step-to-height ratio.
3. The user sets the `desiredHeight`, which is converted into stepper motor steps using:
   ```cpp
   desiredStep = (desiredHeight * maxStep) / maxHeight;
   ```
4. The stepper motor moves upwards to the calculated position.

## Notes & Improvements
- The `delay(1)` in stepping functions should be optimized using `millis()` for better performance.
- Implementing acceleration profiles can improve motor efficiency and prevent sudden movements.
- Add error handling for sensor failures or unexpected motor behavior.

## License
This project is open-source and free to use for educational and research purposes.

