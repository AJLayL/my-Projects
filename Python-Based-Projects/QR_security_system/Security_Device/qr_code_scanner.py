import cv2
import numpy as np
import pyzbar.pyzbar as pyzbar
import os
from visitor_confirmation import confirmation
import tkinter as tk 

#openning cam to scan qr
def qr_scan():
    cap = cv2.VideoCapture(0)
    font = cv2.FONT_HERSHEY_DUPLEX
    x="Yes"
    while True:
        _, frame = cap.read()
        #decode image into 8-bit binary number
        decodedObjects = pyzbar.decode(frame)
        for obj in decodedObjects:
            print(obj.data.decode('utf-8'))
            data= obj.data.decode('utf-8')
            cv2.putText(frame, str(x), (50, 50), 2 , font ,
                        (255, 0, 0), 3)
    
            save_path = './QR_Access_system/'
            name_of_file = str("Visitor_confirmation_2")
            completeName = os.path.join(save_path, name_of_file+".txt")         
        
            file2 = open(completeName, "w")
            toFile = str(data)
        
            file2.write(toFile)
            file2.close()
            
        cv2.imshow("QR scanner", frame)
        
        
        if cv2.waitKey(1) & 0xFF==ord('q'):
                break
        
    
    cv2.destroyAllWindows()
    confirmation() 
    #open GUI window to see status
    label=confirmation()
    m = tk.Tk()
    ourMessage =label
    messageVar = tk.Message(m, text = ourMessage) 
    messageVar.config(bg='lightgreen') 
    messageVar.pack()
    m.mainloop()
    
