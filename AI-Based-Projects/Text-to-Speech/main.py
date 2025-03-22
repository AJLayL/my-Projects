import pyttsx3
import threading
import sys
import keyboard

def read_text_from_file(file_path):
    with open(file_path, 'r') as file:
        text = file.read()
        read_text(text)

def read_text(text):
    engine = pyttsx3.init()
    engine.setProperty('rate', 150)  # Adjust the speed of speech (words per minute)
    engine.setProperty('volume', 0.8)  # Adjust the volume (0.0 to 1.0)

    def stop_engine():
        engine.stop()
        sys.exit()

    engine.say(text)
    engine_thread = threading.Thread(target=engine.runAndWait)
    engine_thread.start()

    while True:
        if keyboard.is_pressed('q'):
            stop_engine()

    engine_thread.join()

# Example usage:
file_path = input("Enter the file path of the text file: ")
read_text_from_file(file_path)
