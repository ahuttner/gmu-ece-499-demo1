import socket
import numpy as np
import cv2
import time

UDP_IP = "laptop-5eeg2bjq.byod.gmu.edu"
UDP_PORT = 5005
cap = cv2.VideoCapture(0)
#Capture frame-by-frame
while True:
        ret, frame = cap.read()
        #Change color to gray
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        #Resize image
        resized = cv2.resize(gray,(200,200))
        #Convert image to string to send over UDP
        vid = resized.tostring()
        sock = socket.socket(socket.AF_INET,
                        socket.SOCK_DGRAM)
        sock.sendto(vid,(UDP_IP,UDP_PORT))
        time.sleep(0.1)

