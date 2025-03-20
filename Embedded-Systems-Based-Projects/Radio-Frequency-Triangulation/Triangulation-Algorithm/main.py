# -*- coding: utf-8 -*-
"""
Created on Wed Oct  7 15:25:21 2020

@author: Amir Amarullah
"""
import math as m
import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

style.use('fivethirtyeight')

ser = serial.Serial('COM8', 9600, timeout=1)
ser.flushInput()
counter = 0

#A1 = float (input ("A1 = "))
#A2 = float (input ("A2 = "))
#c = float (input ("constant base length = "))



while True:
    try:
        data = ser.readline()
        if(len(data)>0):
            strdata = data.decode("utf-8", errors='ignore')
            strdata = strdata.rstrip("\r\n")
            x = strdata.split(",")
            if (len(x)==2):
                    
                A1 = x[0]
                A2 = x[1]
                c = 0.13
                
                
    #            print(A1)
    #            print(A2)
                
                
            #calculate localization
                A1_squared = float (A1)**2
                A2_squared = float (A2)**2
                c_squared = float (c)**2
                
                
                X = (A1_squared - A2_squared + c_squared)/ (2*c)
                Y = m.sqrt(abs(A1_squared - X**2))
#                print ("(X,Y)","=","(",X,",",Y,")")
                f=open("sample.txt", "a+")
                text = X , Y
#                print(text)
                f.write(str(text))
                f.write("\n")
               
        fig = plt.figure()
        ax1 = fig.add_subplot(1,1,1)
        
        def animate(i):
            graph_data = open('sample.txt','r').read()
            lines = graph_data.split('\n')
            xs = []
            ys = []
            for line in lines:
                if len(line)>1:
                    x,y = line.split(',')
                    xs.append(x)
                    ys.append(y)
                    
            ax1.clear()
            ax1.plot(xs,ys)
            
        ani = animation.FuncAnimation(fig,animate,interval=1000)
                
        
                
    except:
        print("error")        