# Arduino Talking Clock with RTC, LCD, and DFPlayer Mini

## Overview
This Arduino project is a **Talking Clock** that announces the time using pre-recorded `.mp3` files stored on a **microSD card** inside a **DFPlayer Mini** module. It features:

- **DS3231 RTC Module** for real-time clock functionality
- **I2C LCD Display** for time and date output
- **DFPlayer Mini Module** for playing `.mp3` audio files
- **LM386 Audio Amplifier** to enhance speaker output
- **Button Input** to trigger time announcement

## Components Used
1. **Arduino Board** (e.g., Uno, Mega)
2. **DS3231 RTC Module**
3. **16x2 I2C LCD Display**
4. **DFPlayer Mini Module**
5. **MicroSD Card** (formatted with `.mp3` audio files)
6. **LM386 Audio Amplifier**
7. **Speaker** (connected via LM386)
8. **Push Button** (to trigger voice playback)
9. **Connecting Wires**

## Libraries Required
Ensure you have the following libraries installed in the Arduino IDE:
- `Wire.h` (for I2C communication)
- `RTClib.h` (for DS3231 RTC support)
- `LiquidCrystal_I2C.h` (for LCD interface)
- `DFRobotDFPlayerMini.h` (for controlling the DFPlayer Mini module)

## Circuit Connections
| Component  | Arduino Pin |
|------------|------------|
| LCD SDA    | A4         |
| LCD SCL    | A5         |
| RTC SDA    | A4         |
| RTC SCL    | A5         |
| DFPlayer RX| Pin 10     |
| DFPlayer TX| Pin 11     |
| DFPlayer Audio Out | LM386 Input |
| LM386 Output | Speaker |
| Button     | Pin 2      |

## Features
- Displays current **time and date** on the LCD
- Categorizes time into **morning (PAGI), afternoon (TENGAHARI), evening (PETANG), and night (MALAM)**
- Plays pre-recorded `.mp3` files corresponding to the **current hour, minutes, and period of the day**
- Uses a **button press** to trigger voice output

## Code Breakdown
### Initialization
- **Sets up LCD, RTC, and DFPlayer Mini module**
- **Checks if DFPlayer Mini is properly initialized**

### Main Loop
1. **Reads real-time data from the DS3231 RTC module**
2. **Displays the current time and date on the LCD**
3. **Categorizes the time into different periods of the day**
4. **Waits for button press to trigger voice playback**
5. **Calls `playTime()` function to play `.mp3` files**

### `playTime()` Function
- Plays corresponding `.mp3` files for **hours (1-12) and minutes (15, 30, 40, 50, etc.)**
- Announces the **time period (morning, afternoon, evening, night)**
- Uses `mp3_play(fileNumber)` function to play the correct `.mp3` file from the DFPlayer Mini

## How to Use
1. Upload the code to an Arduino board.
2. Ensure the **microSD card** inside the DFPlayer Mini contains the required `.mp3` files.
3. Press the **button** to trigger voice playback of the current time.
4. The LCD will update the time and date every second.

## Possible Improvements
- **Fix LCD flickering** by optimizing `lcd.clear()` placement.
- **Improve button debounce handling**.
- **Enhance time announcement logic** for minute precision.
- **Ensure `mp3_isPlaying()` check** before playing new files.

## Notes
- This project is documented as-is and was originally written for a past implementation.
- Future optimizations can be made based on known improvements but are not applied to preserve the original documentation.

## Author
This project was developed as part of a previous Arduino-based audio clock experiment. Future refinements may be made, but the current version remains documented for reference.

