# README

## Overview
This project demonstrates how to use an **nRF24L01** module as a transmitter to send data wirelessly. The provided code configures the nRF24L01 module using an **Arduino** and transmits a simple message periodically.

## Hardware Requirements
- Arduino Board (e.g., Arduino Uno, Nano, Mega)
- nRF24L01 Wireless Transceiver Module
- Jumper Wires

## Wiring Diagram

| nRF24L01 Pin | Arduino Pin |
|-------------|------------|
| VCC         | 3.3V       |
| GND         | GND        |
| CE          | 7          |
| CSN         | 8          |
| SCK         | 13         |
| MOSI        | 11         |
| MISO        | 12         |

**Note:** The nRF24L01 operates at **3.3V**. Do not connect VCC to **5V**, as it may damage the module.

## Software Requirements
- **Arduino IDE** (Latest Version)
- **RF24 Library**
  - Install via Arduino Library Manager: `Sketch` > `Include Library` > `Manage Libraries...` > Search for **RF24** and install it.

## Code Explanation
### 1. **Library Inclusion**
```cpp
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
```
These libraries are required for SPI communication and nRF24L01 functionality.

### 2. **Module Initialization**
```cpp
RF24 radio(7, 8);  // CE, CSN
const byte address[6] = "00001";
```
Defines the radio module object and assigns an address for communication.

### 3. **Setup Function**
```cpp
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  radio.setAutoAck(false);
}
```
- Starts serial communication.
- Initializes the **nRF24L01** module.
- Opens a communication pipe with a specific address.
- Sets the module as a **transmitter** by stopping listening.
- Disables **Auto Acknowledgment** for simpler communication.

### 4. **Loop Function**
```cpp
void loop()
{
  Serial.println("meow");
  delay(2000);
}
```
- Prints "meow" every 2 seconds to the Serial Monitor.
- **Note:** The actual transmission function `radio.write()` is missing.

## Improvements
If you want to send the message via **nRF24L01**, add this inside `loop()`:
```cpp
const char text[] = "meow";
radio.write(&text, sizeof(text));
```

## Next Steps
- Implement a **receiver** using another nRF24L01 module.
- Add **radio.write()** for actual message transmission.
- Use **Auto Acknowledgment** for better reliability.

## License
This project is open-source and can be modified freely.

---
For further assistance, check the [RF24 Library Documentation](https://nrf24.github.io/RF24/).

