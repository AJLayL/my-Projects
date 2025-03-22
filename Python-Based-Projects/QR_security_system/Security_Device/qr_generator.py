#from qr_generator_ import qr_generate
from threading import Timer,Thread,Event
import time
#from try_qrcode import uuid_qr
import current_time_ as time
import qrcode as qr
import uuid
import os

#making a timer class
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

class uuid_qr():
    def __init__(self):
        self.current_number=1
    def generate_qr(self):
        a = uuid.uuid1()
        print(a)
        b = qr.make(a)
        name_save= str('test%d'%(self.current_number))
        save_path = './QR_Access_system/'
        name_of_file = str("Residential_confirmation_1")
        completeName = os.path.join(save_path, name_of_file+".txt")         
        file1 = open(completeName, "w")
        toFile = str(a)

        file1.write(toFile)
        file1.close()
        
        b.save('./QR_Access_system/%s.png'%(name_save))
        time.current_time()


multiple_qr=uuid_qr()
t = perpetualTimer(20,multiple_qr.generate_qr)

t.start()

