import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import calendar, locale
from matplotlib.ticker import MultipleLocator
import numpy as np
""" locale.setlocale(locale.LC_ALL, 'en-EN') """


""" import os;
sistemaop = os.name

print(sistemaop)
 """



""" data = pd.read_csv('C:/work/mirepositorio/2do/python/tarea2/nvda_data.csv')"""
data = pd.read_csv('/Users/user/work/study/2023-2024/Архитектура_компьютера/tareas/mirepositorio/2do/python/tarea2/nvda_data.csv')

data_bit = data[['Datetime','Open',  'High' , 'Low' , 'Close']][:100]


fig = plt.figure(figsize=(10,7))


ax = fig.add_axes([0.1, 0.1, 0.8, 0.8], aspect=5)
ax.yaxis.set_major_locator(MultipleLocator(1))

ax.plot(data_bit['Open'] , 'b-' , label='Open')
ax.plot(data_bit['High'] , 'g-' , label='High')
ax.plot(data_bit['Low'] , 'y-' , label='Low')
ax.plot(data_bit['Close'] , 'c-' , label='Close')

mean = data_bit['Close'].mean()
ax.axhline(data_bit['Close'].median(),  color='c' , linestyle='-.' , label = 'медиана Close')

ax.legend()
ax.set_xlabel('минуты')
ax.set_ylabel('акции компаний')

ax.set_ylim(120,135)
ax.set_xlim(0,100)


bx = plt.figure().add_subplot(projection='3d')
bx.yaxis.set_major_locator(MultipleLocator(20))
xs = np.arange(100)
y1 = data_bit['Open']
y2 = data_bit['High']
y3 = data_bit['Low']
y4 = data_bit['Close']

""" y5 = [1,2,3,4,5,6,7,8,9,10] """




bx.bar(xs, y1, zs=0  , zdir='y', color='b', alpha=0.8)
bx.bar(xs, y2, zs=20  , zdir='y', color='g', alpha=0.8)
bx.bar(xs, y3, zs=40  , zdir='y', color='y', alpha=0.8)
bx.bar(xs, y4, zs=60  , zdir='y', color='c', alpha=0.8)
""" bx.bar(xs, y5, zs=80  , zdir='y', color='r', alpha=0.8) """

bx.set_ylim(0,80)
bx.set_xlim(0,100)

bx.set_zlim(120,135)


plt.xlabel('минуты')
plt.ylabel('сток дата')
plt.legend()

plt.show()

