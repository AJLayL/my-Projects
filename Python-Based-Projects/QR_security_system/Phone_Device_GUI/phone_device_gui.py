# import library
from tkinter import *
from datetime import datetime 
import pyzbar.pyzbar as pyzbar
import os
import cv2
import qrcode
import os.path
import uuid
import time


# Designing window for main screen
def main_account_screen():
    global main_screen
    main_screen = Tk()
    main_screen.geometry("300x250")
    main_screen.title("Account Login")
    Label(text="Select Your Choice", bg="blue", width="300", height="2", font=("Calibri", 13)).pack()
    Label(text="").pack()
    Button(text="Login", height="2", width="30", command = login).pack()
    Label(text="").pack()
    Button(text="Register", height="2", width="30", command=register).pack()

    main_screen.mainloop()

# Designing window for registration    
def register():

    global register_screen
    register_screen = Toplevel(main_screen)
    register_screen.title("Register")
    register_screen.geometry("300x250")
    global username
    global password
    global username_entry
    global password_entry
    username = StringVar()
    password = StringVar()

    Label(register_screen, text="Please enter details below", bg="blue").pack()
    Label(register_screen, text="").pack()
    username_lable = Label(register_screen, text="Username * ")
    username_lable.pack()
    username_entry = Entry(register_screen, textvariable=username)
    username_entry.pack()
    password_lable = Label(register_screen, text="Password * ")
    password_lable.pack()
    password_entry = Entry(register_screen, textvariable=password, show='*')
    password_entry.pack()
    Label(register_screen, text="").pack()
    Button(register_screen, text="Register", width=10, height=1, bg="blue", command = register_user).pack()


# Designing window for login
def login():
    
    global login_screen
    login_screen = Toplevel(main_screen)
    login_screen.title("Login")
    login_screen.geometry("300x250")
    Label(login_screen, text="Please enter details below to login").pack()
    Label(login_screen, text="").pack()

    global username_verify
    global password_verify

    username_verify = StringVar()
    password_verify = StringVar()

    global username_login_entry
    global password_login_entry

    Label(login_screen, text="Username * ").pack()
    username_login_entry = Entry(login_screen, textvariable=username_verify)
    username_login_entry.pack()
    Label(login_screen, text="").pack()
    Label(login_screen, text="Password * ").pack()
    password_login_entry = Entry(login_screen, textvariable=password_verify, show= '*')
    password_login_entry.pack()
    Label(login_screen, text="").pack()
    Button(login_screen, text="Login", width=10, height=1, command = login_verify).pack()
    

# Implementing event on register button
def register_user():

    username_info = username.get()
    password_info = password.get()
    file = open(username_info, "w")
    file.write(username_info + "\n")
    file.write(password_info)
    file.close()

    Label(register_screen, text="Registration Success", fg="green", font=("calibri", 11)).pack()

# function verify username and password resident
def login_verify():
    username1 = username_verify.get()
    password1 = password_verify.get()

    list_of_files = os.listdir()
    if username1 in list_of_files:
        file1 = open(username1, "r")
        verify = file1.read().splitlines()
        if password1 in verify:
            login_sucess()

        else:
            password_not_recognised()

    else:
        user_not_found()
        
        
        
        
        
#initialize Qr code size        
qr = qrcode.QRCode(
    version=1,
    box_size=15,
    border=5
    )

#function generate qr using uuid
def qr_generate():
    
    data= uuid.uuid1()
    qr.add_data(data)
    qr.make(fit=True)
    img = qr.make_image (fill='black', color='white')
    img.save('uuid_for_visitor.png')
    img = cv2.imread ('uuid_for_visitor.png')
    
    save_path = './QR_Access_system/'
    name_of_file = str("Visitor_confirmation_1")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file1 = open(completeName, "w")
    toFile = str(data)
    
    file1.write(toFile)
    file1.close()
    
    save_path = './QR_Access_system/'
    name_of_file = str("dummy1")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file1 = open(completeName, "w")
    toFile = str('1')
    
    file1.write(toFile)
    file1.close()
    
    print(data)
    
    
# Designing popup for login success

def login_sucess():
    
    global login_success_screen
    login_success_screen = Toplevel(login_screen)
    login_success_screen.title("Success")
    login_success_screen.geometry("150x100")
    Label(login_success_screen, text="Login Success").pack()
    Button(login_success_screen, text="OK", command=choose_access_type).pack()
    
    main_screen.destroy

# Designing popup for login invalid password

def password_not_recognised():
    global password_not_recog_screen
    password_not_recog_screen = Toplevel(login_screen)
    password_not_recog_screen.title("Success")
    password_not_recog_screen.geometry("150x100")
    Label(password_not_recog_screen, text="Invalid Password ").pack()
    Button(password_not_recog_screen, text="OK", command=delete_password_not_recognised).pack()

# Designing popup for user not found

def user_not_found():
    global user_not_found_screen
    user_not_found_screen = Toplevel(login_screen)
    user_not_found_screen.title("Success")
    user_not_found_screen.geometry("150x100")
    Label(user_not_found_screen, text="User Not Found").pack()
    Button(user_not_found_screen, text="OK", command=delete_user_not_found_screen).pack()
    
# Designing window for access type for resident
def choose_access_type():
    
    login_success_screen.destroy()
    global access_type
    
    access_type = Tk()
    access_type.geometry("300x250")
    access_type.title("access type")
    Label(access_type,text="Select Your Choice", bg="blue", width="300", height="2", font=("Calibri", 13)).pack()
    Label(access_type,text="").pack()
    Button(access_type,text="Resident", height="2", width="30", command = qr_scan).pack()
    Label(access_type,text="").pack()
    Button(access_type,text="Visitor", height="2", width="30", command = download_success).pack()

    access_type.mainloop()
    
    
# Designing popup for download QR image success    
def download_success():
    
    qr_generate()
    global download_success_screen
    download_success_screen = Tk()
    download_success_screen.title("Success")
    download_success_screen.geometry("150x100")
    Label(download_success_screen, text="QR Image Downloaded").pack()
    Button(download_success_screen, text="OK", command=delete_download_success).pack()
    
    download_success_screen.mainloop()
    
# function open QR code scanner
def qr_scan():
       
    cap = cv2.VideoCapture(0)
    font = cv2.FONT_HERSHEY_DUPLEX
    x="Yes"
    while True:
        _, frame = cap.read()
    
        decodedObjects = pyzbar.decode(frame)
        for obj in decodedObjects:
            print(obj.data.decode('utf-8'))
            cv2.putText(frame, str(x), (50, 50), 2 , font ,
                        (255, 0, 0), 3)
    
            save_path = './QR_Access_system/'
            name_of_file = str("Residential_confirmation_2")
            completeName = os.path.join(save_path, name_of_file+".txt")         
        
            file2 = open(completeName, "w")
            toFile = str(obj.data.decode('utf-8'))
        
            file2.write(toFile)
            file2.close()
        cv2.imshow("Resident scanner", frame)
        if cv2.waitKey(1) & 0xFF==ord('q'):
                break
    
    cv2.destroyAllWindows()
    confirmation()
    
    label=confirmation()
    m = tk.Tk()
    ourMessage =label
    messageVar = tk.Message(m, text = ourMessage) 
    messageVar.config(bg='lightgreen') 
    messageVar.pack()
    Button(m, text="OK", command=m.destroy).pack()
    m.mainloop()
    
# function confirmation of qr code scanner process  
def confirmation():
    username1 = username_verify.get()
    save_path = './QR_Access_system/'
    name_of_file = str("Residential_confirmation_1")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file1 = open(completeName, "r")
    
    save_path = './QR_Access_system/'
    name_of_file = str("Residential_confirmation_2")
    completeName = os.path.join(save_path, name_of_file+".txt")         
    
    file2 = open(completeName, "r")
    
    x= file1.read()
    y= file2.read()
    
    if (x==y):
        label="Success"
        now = datetime.now()
        print(username1)

        dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
        print(dt_string)	

        save_path = './QR_Access_system/'
        name_of_file = str("date_from_user_device")
        completeName = os.path.join(save_path, name_of_file+".txt")         
        
        file2 = open(completeName, "w")
        toFile = str(dt_string)
        
        file2.write(toFile)
        file2.close()

    else:
        label="Try Again!"
    
    print(label)
    return label


# Deleting popups    
    
def delete_download_success():
    download_success_screen.destroy()


def delete_password_not_recognised():
    password_not_recog_screen.destroy()


def delete_user_not_found_screen():
    user_not_found_screen.destroy()
    


#call main screen function

main_account_screen()