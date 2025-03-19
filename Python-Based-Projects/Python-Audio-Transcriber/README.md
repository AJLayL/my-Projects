Audio to Text Transcriber
Overview
This Python application allows users to transcribe audio files (MP3, M4A) into text and save them as Word documents (.docx). The program uses Tkinter for GUI interaction, pydub for audio format conversion, and speech_recognition for speech-to-text processing.

Features
✅ Convert MP3 and M4A audio files to text
✅ Save transcribed text as a Word document (.docx)
✅ Simple GUI for file selection
✅ Uses Google Speech Recognition for accurate transcription

Installation
Ensure you have Python installed (≥3.7). Then install the required dependencies using:

## Usage
1. Run the script:
```sh
    pip install tkinter speechrecognition pydub python-docx
```
Additionally, install ffmpeg (required for pydub to process audio):
Windows: Download ffmpeg.exe from https://ffmpeg.org/download.html and add it to the system PATH.
Usage
Run the script:
```sh
    python transcriber.py
```
Click the "Choose Audio File" button to select an MP3 or M4A file.
The app will transcribe the audio and save the text as a .docx file in the same directory.
Dependencies
tkinter – GUI framework
speech_recognition – Speech-to-text conversion
pydub – Audio conversion
python-docx – Word document creation
License
This project is licensed under the MIT License.

