import cv2
import sys
test = 0

cascPath = (cv2.data.haarcascades + "haarcascade_frontalface_default.xml")
faceCascade = cv2.CascadeClassifier(cascPath)

video_capture = cv2.VideoCapture(0)

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
        test = x
    # Display the resulting frame
    cv2.imshow('Video', frame)
        
    if (test < 100):
        print("Right")
    if cv2.waitKey(1) & 0xFF == 27: #or ord('a') for specific keyboard keys
        break
    
    

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()