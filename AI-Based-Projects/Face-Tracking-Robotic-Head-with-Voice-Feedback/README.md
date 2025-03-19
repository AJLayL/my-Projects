# Face-Tracking Robotic Head with Voice Feedback

## Description
This project utilizes OpenCV for real-time face detection and controls servo motors to track movement. The system is built using an Adafruit PCA9685 servo driver and provides voice feedback using Google Text-to-Speech (gTTS). It is designed to recognize human faces and adjust servo angles to follow detected movement.

## Features
- **Real-time Face Tracking:** Uses OpenCV's Haar cascade to detect faces.
- **Servo Control:** Adjusts servos dynamically to follow face movement.
- **Voice Feedback:** Plays an AI-generated voice message when a face is detected.
- **Automated Motion Handling:** Moves servos in response to face position.

## Installation
1. Install required dependencies:
   ```bash
   pip install opencv-python Adafruit-PCA9685 gtts pydub
    ```
2. Ensure OpenCV's Haar cascade is installed. The default path in the script is:
    ```
    C:\python\Lib\site-packages\cv2\data\haarcascade_frontalface_alt.xml
    ```
3. Set up the Adafruit PCA9685 module to control the servos.
4. Connect a webcam for real-time face detection.

Usage
Run the script:
    ```
    python face_tracking_robot.py
    ```
- The robotic head will move servos to follow faces.
- A voice message will be played when a face is detected.
- Press Esc to exit.

Hardware Requirements
- Adafruit PCA9685 (Servo Driver Board)
- Servo Motors (at least two for movement)
- Webcam (for face detection)
- Raspberry Pi / PC (running Python)

Troubleshooting
- Ensure the webcam is properly connected and detected by OpenCV.
- If servos are not responding, check PCA9685 wiring and power supply.
- If no audio output, confirm gTTS and pydub are installed.