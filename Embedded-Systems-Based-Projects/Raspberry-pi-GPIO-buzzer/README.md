# Raspberry Pi Buzzer Alarm

## Description
This project uses a **buzzer** connected to a Raspberry Pi to generate a **beeping sound** at regular intervals. It utilizes the **RPi.GPIO** library to control the buzzer via **GPIO pin 16**.

## Features
- Uses **GPIO.BCM** mode for pin referencing.
- **Turns the buzzer ON and OFF** every **0.2 seconds**.
- Runs in an **infinite loop** for continuous beeping.
- Simple and efficient **hardware alert system**.

## Hardware Requirements
- Raspberry Pi (any model with GPIO support)
- **Buzzer** module
- **Jumper wires**

## Wiring Guide
| **Pin** | **Connection** |
|---------|--------------|
| GPIO 16 | **Buzzer Positive (+)** |
| GND     | **Buzzer Negative (-)** |

## Dependencies
Ensure **Python 3** and **RPi.GPIO** are installed:

```bash
pip install RPi.GPIO
```

## Installation & Usage
Clone this repository:

```bash
git clone https://github.com/your-username/rpi-buzzer.git
cd rpi-buzzer
```

Run the script:

```bash
python3 buzzer.py
```
The buzzer will start beeping every 0.2 seconds.

**Stopping the Script**
- Press CTRL + C to stop the buzzer and exit the script safely.

**Customization**
Change the buzzer pin by modifying this line:
```python
buzzer = 16  # Change to your desired GPIO pin
```
**Adjust the beeping frequency by modifying:**
```python
time.sleep(0.2)  # Change 0.2 seconds to desired interval
```