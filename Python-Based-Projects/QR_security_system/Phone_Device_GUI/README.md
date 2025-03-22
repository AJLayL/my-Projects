# QR Access System

## Overview
The QR Access System is a Python-based application that provides a secure login system and QR code-based access control for residents and visitors. The system allows users to register, log in, generate QR codes for visitors, and scan QR codes for resident access verification.

## Features
- **User Registration & Login**: Allows users to create accounts and log in securely.
- **QR Code Generation**: Generates unique QR codes for visitor access.
- **QR Code Scanning**: Uses a webcam to scan QR codes for resident verification.
- **File-Based User Storage**: Stores user credentials in local files.
- **GUI Interface**: Built using Tkinter for a simple and interactive user experience.

## Requirements
To run the QR Access System, ensure you have the following dependencies installed:
```sh
pip install opencv-python pyzbar qrcode
```

## How It Works
1. **User Registration**
   - Users can register by entering a username and password.
   - The credentials are stored in a local file with the username as the filename.

2. **User Login**
   - Users enter their username and password to log in.
   - The system verifies credentials against stored files.

3. **Choosing Access Type**
   - After a successful login, users select either "Resident" or "Visitor".

4. **Visitor QR Code Generation**
   - A QR code is generated using a UUID and saved as an image.
   - A confirmation text file is created with the UUID.

5. **Resident QR Code Scanning**
   - Residents scan their QR code using a webcam.
   - The scanned QR code is verified against stored confirmation data.

## Usage
Run the following command to start the application:
```sh
python script.py
```

## File Structure
```
QR_Access_System/
|-- script.py          # Main application script
|-- QR_Access_system/  # Stores generated QR codes and confirmation files, This utilises file sharing. different device same network. 
|-- uuid_for_visitor.png # Generated visitor QR code
```

## Known Issues & Future Improvements
- Currently, user credentials are stored in plain text files, which is a security risk. Consider using hashed passwords.
- The application does not yet support a database for user management.
- Add support for email or SMS-based QR code sharing for visitors.
- Improve the GUI with better styling and user feedback.

## Author
Developed by [Your Name]. Contributions and suggestions are welcome!

