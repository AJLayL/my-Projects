#python transcriber
import tkinter as tk
from tkinter import filedialog
import speech_recognition as sr
from pydub import AudioSegment
from docx import Document
import os

def convert_to_wav(audio_file):
    # Convert audio file to WAV format using pydub
    sound = AudioSegment.from_file(audio_file)
    wav_file = audio_file.replace(".{}".format(audio_file.split('.')[-1]), ".wav")
    sound.export(wav_file, format="wav")
    return wav_file

def transcribe_audio(audio_file):
    # Convert audio file to WAV
    wav_file = convert_to_wav(audio_file)

    # Load the audio file directly using SpeechRecognition
    r = sr.Recognizer()
    with sr.AudioFile(wav_file) as source:
        audio = r.record(source)

    # Transcribe the audio using SpeechRecognition
    text = r.recognize_google(audio)

    # Create a new Word document
    doc = Document()
    doc.add_paragraph(text)

    # Save the document as a Word file
    doc_file = audio_file.replace(".{}".format(audio_file.split('.')[-1]), ".docx")
    doc.save(doc_file)
    print("Transcription saved as", doc_file)

    # Clean up temporary WAV file
    os.remove(wav_file)

def choose_file():
    # Open file dialog to select the audio file
    file_path = filedialog.askopenfilename(filetypes=[("Audio files", ("*.mp3", "*.m4a"))])
    if file_path:
        # Call the transcription function
        transcribe_audio(file_path)

# Create the Tkinter window
window = tk.Tk()
window.title("Audio to Docx Transcriber")

# Create a button to choose the file
button = tk.Button(window, text="Choose Audio File", command=choose_file)
button.pack(pady=20)

# Run the Tkinter event loop
window.mainloop()
