#visitor confirmation
import os
import tkinter as tk
from datetime import datetime
def confirmation():
#read uiid visitor QR generator  
    save_path = './QR_Access_system/'
    name_of_file = str("Visitor_confirmation_1")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file1 = open(completeName, "r")
    
#read file visitor decode QR    
    save_path = './QR_Access_system/'
    name_of_file = str("Visitor_confirmation_2")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file2 = open(completeName, "r")
 
    
#compare UIID from both file
    x= file1.read()
    y= file2.read()
#if uiid same success   
    if (x==y):
        label="Success!"
        now = datetime.now()
        print("visitor")
        dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
        print(dt_string)	

        save_path = './QR_Access_system/'
        name_of_file = str("Visitor_time")
        completeName = os.path.join(save_path, name_of_file+".txt")         
        
        file2 = open(completeName, "w")
        toFile = str(dt_string)
        
        file2.write(toFile)
        file2.close()
        
        
        
#if not same try again       
    else:
        label="Try Again!"
    
    print(label)
    return label
#popup comfirmation status
    label=confirmation()
    
    m = tk.Tk()
    ourMessage =label
    messageVar = tk.Message(m, text = ourMessage) 
    messageVar.config(bg='lightgreen') 
    messageVar.pack( ) 
    
    m.mainloop()
    return xbeng
