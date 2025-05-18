import pyautogui, webbrowser

from time import sleep

#webbrowser.open('https://web.whatsapp.com/send?phone=+51932297250')

sleep(5)

for i in range(100):
    pyautogui.typewrite('hello')
    pyautogui.press('enter')