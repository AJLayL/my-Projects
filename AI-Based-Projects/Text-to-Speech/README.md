# Python Text-to-Speech Reader

## Overview
This Python script reads text from a file and converts it into speech using the `pyttsx3` library. It also allows users to stop the speech playback by pressing the 'q' key.

## Features
- Reads text from a file and converts it into speech.
- Uses `pyttsx3` for offline text-to-speech conversion.
- Allows speech rate and volume adjustment.
- Stops speech playback when 'q' is pressed.

## Requirements
Ensure you have the following dependencies installed:

```bash
pip install pyttsx3 keyboard
```

## How to Use
1. Run the script in a terminal or command prompt:
   ```bash
   python main.py
   ```
2. Enter the file path containing the text to be read when prompted.
3. The script will read the text aloud.
4. Press 'q' at any time to stop the speech playback.

## Code Breakdown
### 1. Reading Text from a File
- The script prompts the user for a file path and reads the contents.

### 2. Text-to-Speech Conversion
- Uses `pyttsx3` to convert text to speech.
- Allows customization of **speech rate** and **volume**.

### 3. Stopping Speech Playback
- Listens for the 'q' key press using the `keyboard` module.
- Stops the speech engine and exits the script when 'q' is pressed.

## Notes
- The script runs synchronously and will keep running until the speech is finished or 'q' is pressed.
- The `keyboard` module requires administrative privileges on some systems.

## Possible Improvements
- Add support for pausing/resuming speech.
- Implement GUI for easier interaction.
- Allow real-time text input instead of reading from a file.

## Author
This script was created as a simple offline text-to-speech reader using Python.
