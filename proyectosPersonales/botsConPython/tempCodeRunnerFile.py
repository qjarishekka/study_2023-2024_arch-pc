import pyautogui, webbrowser

from time import sleep




webbrowser.open('https://web.whatsapp.com/send?phone=+51965745160')

sleep(10)

for i in range(10):
    pyautogui.typewrite('akira')
    pyautogui.press('enter')