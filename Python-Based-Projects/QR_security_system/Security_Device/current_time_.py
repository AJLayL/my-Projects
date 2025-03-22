from datetime import datetime
import os
#install datetime
def current_time():
    now = datetime.now()
    
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    print(dt_string)	
    
    save_path = './QR_Access_system/'
    name_of_file = str("save_current_time")
    completeName = os.path.join(save_path, name_of_file+".txt")         
            
    file2 = open(completeName, "w")
    toFile = str(dt_string)
            
    file2.write(toFile)
    file2.close()