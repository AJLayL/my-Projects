# Real-Time Face Detection with OpenCV

## Description
This Python project uses OpenCV to perform real-time face detection. It utilizes Haar cascades to identify faces and draws a bounding box around detected faces in a live webcam feed. The script also prints "Right" when a face is detected in a specific region.

## Features
- **Real-time face detection** using OpenCV.
- **Haar cascade classifiers** for face recognition.
- **Region-based detection feedback** (prints "Right" when a face appears in a specific area).
- **Simple and lightweight implementation**.

## Installation
1. Install OpenCV:
   ```sh
   pip install opencv-python
   ```
2. Ensure your webcam is connected and recognized by the system.

## Usage
Run the script:
```sh
python face_detection.py
```
- A window will open, displaying the video feed.
- Faces detected will be highlighted with a green rectangle.
- If a face appears in the leftmost region (`x < 100`), it prints `"Right"`.
- Press `Esc` to exit.

## Requirements
- **Python 3+**
- **OpenCV (`opencv-python`)**
- **Webcam (for real-time detection)**

## Troubleshooting
- If the camera feed is not displaying, check the webcam connection.
- Ensure OpenCV is installed correctly.
- Modify the `cascPath` to match your OpenCV installation if needed.

## License
This project is open-source and free to use.

