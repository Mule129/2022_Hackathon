import time
import serial

a = serial.Serial("COM7", 9600)
print(a)
t = ""
while True:
    a.write("test".encode())
    
    t = a.readline()
    print(t.decode())
    time.sleep(0.1)
