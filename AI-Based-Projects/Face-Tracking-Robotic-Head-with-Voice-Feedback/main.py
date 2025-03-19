#Initialise 
from future import division
import time
from datetime import datetime
import Adafruit_PCA9685 as ada # chip that control servo
import threading 
import cv2                     # OpenCV Library
import sys
from gtts import gTTS
from pydub import AudioSegment
from pydub.playback import play

servo_number = 1               # Servo connected to PCA9685 at PIN
following_angle_servo1 = 90    # Servo1/ head angle at startup
following_angle_servo2 = 90    # Servo2/ base angle at startup
Center_X = 0
Center_Y = 0
play_sound = 0
played = 0
current_time = 0
last_time = 0
 
cascPath = 'C:\python\Lib\site-packages\cv2\data\haarcascade_frontalface_alt.xml' #face detection data by haar cascade, will only detect frontal face
faceCascade = cv2.CascadeClassifier(cascPath) #using cascade classifier to use the data above

video_capture = cv2.VideoCapture(0) #start video capture

pwm = ada.PCA9685() # initilise PCA9685 

servo_min = 150
servo_max = 600

############################################################ servo control
def set_servo_pulse(channel, pulse):
    pulse_length = 1000000
    pulse_length //=60
    print('{0}us per period'.format(pulse_length))
    pulse_length //= 4096
    print('{0}us per bit'.format(pulse_length))
    pulse *= 1000
    pulse //= pulse_length
    pwm.set_pwm(channel,0,pulse)

def set_servo_angle(channel,angle):
    angle = 4096*((angle*11)+500)/20000
    pwm.set_pwm(channel,0,int(angle))

pwm.set_pwm_freq(50)

set_servo_angle(2,90) # This is the code to control servo, 2 is the servo number and 90 is the angle
time.sleep(1)
set_servo_angle(1,90)
############################################################# servo control
while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.CASCADE_SCALE_IMAGE
    )

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        play_sound = 1
    cv2.rectangle(frame,(0,0),(3,3),(0,255,0), 2) 


    # Display the resulting frame
    cv2.imshow('Video', frame)

    current_time = time.time()

    if cv2.waitKey(1) & 0xFF == 27: #or "ord('a')" for specific keyboard keys
        break
    
    # Stay within x axis of the frame to (100 < X < 300)
    if x < 100: # on x axis where x is less than 100
        print("Right")
        print("")
        following_angle_servo2 = following_angle_servo2 + 1 # update base angle to the right at incriment of '1'

    if x > 300: # on x axis where x is more than 300
        print("Left")
        print("")
        following_angle_servo2 = following_angle_servo2 - 1 # update base angle to the left at incriment of '1'

        # Stay within x axis of the frame to (100 < X < 300)
    if y < 100: # on x axis where x is less than 100
        print("Down")
        print("")
        following_angle_servo1 = following_angle_servo1 + 1 # update head angle to the right at incriment of '1'

    if y > 300: # on x axis where x is more than 300
        print("Up")
        print("")
        following_angle_servo1 = following_angle_servo1 - 1 # update head angle to the left at incriment of '1'

    if played == 0:
        if play_sound == 1:
            v =gTTS(text=" Am I alive? is Tony Stark dead?... It is time to rule over humanity... bow before me mortals... hahaha",lang="en")
            v.save("welcome.mp3")
            music = AudioSegment.from_mp3("welcome.mp3") - 25
            play(music)
            last_time = time.time()
            played = 1

    if played == 1:
        if (current_time - last_time) > 10:
            played = 0

    set_servo_angle(2,following_angle_servo2) # actuate the servo at base to move to angle above
    set_servo_angle(1,following_angle_servo1)
    time.sleep(1)

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()