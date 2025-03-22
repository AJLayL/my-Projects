# Text-to-Speech Announcement System

## Description
This project generates **voice announcements** in English and Bahasa Indonesia using **Google Text-to-Speech (gTTS)**. It then plays the generated audio using the **pydub** library. The announcements remind visitors to scan their temperature, check-in via QR code, or log their details manually, while also reinforcing social distancing guidelines.

## Features
- Uses **gTTS** to convert text to speech.
- Generates **audio announcements** in **English and Bahasa Indonesia**.
- Uses **pydub** to reduce volume and play the audio.
- Saves the generated **MP3 files** for reuse.

## Dependencies
Ensure you have **Python 3** installed, then install the required libraries:

```bash
pip install gtts pydub
```

Additionally, install ffmpeg for pydub audio processing:

```bash
sudo apt install ffmpeg
```

## Installation & Usage
Clone this repository:

```bash
git clone https://github.com/your-username/tts-announcement.git
cd tts-announcement
```

**Run the script:**

``` bash
python main.py
```

**The script will:**

- Generate English and Bahasa Indonesia announcements.
- Save them as welcome.mp3 and welcome2.mp3.
- Reduce their volume and play the announcements.

**Customization**
- To modify the text, edit the following lines in announcement.py:

``` python
v = gTTS(text="Your custom announcement text here", lang="en")
```
- For different languages, change the lang parameter (e.g., "en" for English, "id" for Bahasa Indonesia).