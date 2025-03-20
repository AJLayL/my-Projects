# RF Data Acquisition using nRF24L01

## Overview
This project sets up an RF data acquisition system using the **nRF24L01** wireless transceiver module. The Arduino-based receiver captures timestamped data from a transmitter and computes the time difference between consecutive transmissions.

## Features
- Uses **nRF24L01** for wireless communication.
- Receives **timestamped data** from the transmitter.
- Computes the time difference between successive transmissions.
- Outputs the received data and time difference to the **serial monitor**.

## Hardware Requirements
- Arduino (Uno, Mega, or similar)
- nRF24L01 transceiver module
- Jumper wires

## Software Requirements
- Arduino IDE
- Required libraries:
  - `SPI.h`
  - `nRF24L01.h`
  - `RF24.h`

## Wiring Guide
| Arduino Pin | nRF24L01 Pin |
|------------|-------------|
| 3.3V       | VCC         |
| GND        | GND         |
| 7          | CE          |
| 8          | CSN         |
| 11         | MOSI        |
| 12         | MISO        |
| 13         | SCK         |

## Installation
1. Install the **Arduino IDE** if not already installed.
2. Install the required libraries through the **Library Manager**.
3. Connect the **nRF24L01** module to the Arduino following the wiring guide.
4. Upload the **receiver code** to the Arduino board.

## Usage
1. Power on both the **transmitter** and **receiver** modules.
2. Open the **Serial Monitor** (9600 baud rate) in the Arduino IDE.
3. Observe the received timestamp values and the calculated time difference between transmissions.

## Code Explanation
- Initializes the **nRF24L01** module and sets it as a **receiver**.
- Reads incoming **timestamp** data sent from the transmitter.
- Calculates the **difference** between successive timestamps.
- Prints the **timestamp** and **time difference** to the Serial Monitor.

## Known Issues
- **Packet Loss:** May occur due to interference or range limitations.
- **Timing Accuracy:** Depends on the precision of the transmitting module.
- **Initialization Failures:** Ensure power and wiring connections are correct.

## Future Improvements
- Implement **error handling** for failed transmissions.
- Add **data validation** to ensure proper formatting.
- Optimize **timestamp synchronization** for better accuracy.

