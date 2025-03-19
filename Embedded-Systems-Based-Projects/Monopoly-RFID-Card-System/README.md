# Monopoly RFID Card System

## Description
This project is an RFID-based transaction system for Monopoly. Instead of handling cash manually, players use RFID cards to store and exchange in-game money. The system uses an MFRC522 RFID module to read card data, an LCD screen for displaying balances, and buttons/joysticks for modifying transaction amounts. 

## Features
- Uses RFID cards to track player balances.
- Allows players to adjust and confirm transactions.
- Displays transaction details on a 16x2 LCD.
- Includes preset increments for quick balance adjustments.

## Hardware Requirements
- Arduino board
- MFRC522 RFID Module
- LiquidCrystal I2C 16x2 LCD
- Joystick module (for transaction adjustments)
- Push buttons (for confirming transactions)
- Connecting wires

## Installation
1. Connect the hardware components according to the pin configuration in the code.
2. Install the necessary libraries in the Arduino IDE:

## Include these libraries:
- Wire.h
- LiquidCrystal_I2C.h
- SPI.h
- MFRC522.h

3. Upload the provided code to your Arduino board.

## Usage
1. Power on the system.
2. Use the joystick to adjust the transaction amount.
3. Place an RFID card on the reader.
4. Press the confirmation button to update the balance.
5. The updated balance is displayed on the LCD screen.

## Future Enhancements
- Implement card-specific transaction history.
- Add wireless communication for centralized balance tracking.
- Improve user interface for better navigation.

## License
This project is open-source. Feel free to modify and enhance it.

