Shortcuts simplify My Drive … 
In the coming weeks, items in more than one folder will be replaced by shortcuts. Access to files and folders won't change.Learn more

import serial
from pynput import keyboard
s=serial.Serial('COM3',9600)

def on_release(key):
    s.write(b'S')
    return False
damn='c'   
def on_press(key):
    global damn
    damn=key.char
    return False    
    
for i in range(10000):

    with keyboard.Listener(
        on_press=on_press) as listener:
         listener.join()
    if damn=='w':
        s.write(b'F')
        with keyboard.Listener(
        on_release=on_release) as listener:
         listener.join()
    if  damn=='s':
        s.write(b'B')
        with keyboard.Listener(
        on_release=on_release) as listener:
         listener.join()
    if  damn=='a':
        s.write(b'L')
        with keyboard.Listener(
        on_release=on_release) as listener:
         listener.join()
    if  damn=='d':
        s.write(b'R')
        with keyboard.Listener(
        on_release=on_release) as listener:
         listener.join()
    
    if damn=='o':
        s.write(b'O')
    if damn=='p':
        s.write(b'o')





