import tkinter as tk
from PIL import ImageTk, Image
from threading import Timer,Thread,Event
from qr_code_scanner_ import qr_scan
from qr_code_scanner_ import confirmation

#Using Class we set the timer using Threading library so that it will not bother the GUI
class perpetualTimer():

   def __init__(self,t,hFunction):
      self.t=t
      self.hFunction = hFunction
      self.thread = Timer(self.t,self.handle_function)

   def handle_function(self):
      self.hFunction()
      self.thread = Timer(self.t,self.handle_function)
      self.thread.start()

   def start(self):
      self.thread.start()

   def cancel(self):  
      self.thread.cancel()

root = tk.Tk()#opening root window
path= './QR_Access_system/test1.png'
img = ImageTk.PhotoImage(Image.open(path))
panel = tk.Label(root, image=img)
root.title("Resident Access")
panel.pack( fill="both", expand="yes")
button = tk.Button(root, text='Visitor', width=30, height=5, command=qr_scan) 
button.pack(side="bottom")


#to refresh the image every 5 interval
def callback():
    img2 = ImageTk.PhotoImage(Image.open(path))
    panel.configure(image=img2)
    panel.image = img2

t = perpetualTimer(5,callback)#using the timer with 5 second interval to open function callback
t.start()
root.mainloop()