# Real-Time Localization with Serial Data and Matplotlib Animation

## Overview
This project reads real-time data from a serial port, processes the data to calculate coordinates using a mathematical formula, and visualizes the results dynamically using Matplotlib.

## Features
- Reads sensor data from a serial port (COM8 at 9600 baud rate)
- Processes localization data using mathematical equations
- Stores the computed coordinates in a text file (`sample.txt`)
- Animates the recorded data in real-time using Matplotlib

## Requirements
- Python 3.x
- Required libraries:
  - `math`
  - `serial`
  - `matplotlib`

## Installation
1. Install Python 3 if not already installed.
2. Install the required libraries using pip:
   ```sh
   pip install pyserial matplotlib
   ```
3. Ensure the correct serial port is specified in the script (`COM8` in this case).

## Usage
1. Connect the device sending serial data.
2. Run the script:
   ```sh
   python script.py
   ```
3. The program will continuously read data, calculate localization coordinates, store them in `sample.txt`, and visualize them dynamically.

## Code Explanation
- Expecting data from 'RF-data-acquisition' setup, opens a serial connection and continuously reads incoming data.
- Parses the data into two values (A1 and A2) and applies the localization formula.
- Saves the calculated `(X, Y)` coordinates into `sample.txt`.
- Uses Matplotlib's `FuncAnimation` to update the plot dynamically.

## Known Issues
- The error handling is minimal (`except` only prints "error").
- The animation function is inside the loop, which may cause performance issues.
- The file `sample.txt` is opened repeatedly instead of being managed efficiently.

## Future Improvements
- Improve exception handling to display more informative error messages.
- Optimize file handling to reduce redundant writes.
- Refactor the animation function to work efficiently outside the main loop.

