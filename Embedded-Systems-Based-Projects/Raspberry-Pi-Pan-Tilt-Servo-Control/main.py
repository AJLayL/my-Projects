# Raspberry Pi Servo control, 2 servo controlling the position of a non-istalled camera. 
# 1 servo for the x axis and the other for y axis. 

from __future__ import division
import time
import Adafruit_PCA9685
import RPi.GPIO as GPIO
servoHead = 0
servoBody = 0

pwm = Adafruit_PCA9685.PCA9685(address=0x41,busnum=1)
#pwm = Adafruit_PCA9685.PCA9685()


servo_min = 150
servo_max = 600


def set_servo_pulse(channel, pulse):
    pulse_length = 1000000
    pulse_length //=60
    print('{0}us per period'.format(pulse_length))
    pulse_length //= 4096
    print('{0}us per bit'.format(pulse_length))
    pulse *= 1000
    pulse //= pulse_length
    pwm.set_pwm(channel,10,pulse)

def set_servo_angle(channel,angle):
    angle = 4096*((angle*11)+500)/20000
    pwm.set_pwm(channel,10,int(angle))

pwm.set_pwm_freq(10)

while(True):
    
    servoHead = int(input("what is angle for head? (0 up, 180 down):_ "))
    servoBody = int(input("what is angle for body? (0 Right, 180 Left):_ "))
    
    time.sleep(1)
    set_servo_angle(1,servoHead)
    time.sleep(1)


    time.sleep(1)
    set_servo_angle(2,servoBody)
    time.sleep(1)

    print('Moving servo on channel 0, press Ctrl-c to quit...')

