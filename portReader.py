import serial as sr
import keyboard

ser = sr.Serial('COM7', 9600)

import webbrowser

# Specify the path to your HTML file
file_path = 'password.html'

# Open the HTML file in a new tab
webbrowser.open_new_tab(file_path)

while True:
    if(ser.in_waiting > 0):
        line = ser.readline().decode('utf-8').strip()
        if line.startswith("Key "):
            key, state = line.split(" ")[1:]
            if state == "PRESSED.":
                keyboard.press_and_release(key)
