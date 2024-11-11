import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import calendar, locale
from matplotlib.ticker import MultipleLocator
""" locale.setlocale(locale.LC_ALL, 'en-EN') """


""" import os;
sistemaop = os.name

print(sistemaop)
 """



data = pd.read_csv('C:/work/mirepositorio/2do/python/tarea2/index.csv')
data_bit = data[['Year','Federal Funds Target Rate']]


locator = mdates.AutoDateLocator()
formatter = mdates.AutoDateFormatter(locator)

fig = plt.figure(figsize=(9,5))

ax = fig.add_axes([0.1, 0.1, 0.8, 0.8], aspect=30)



ax.xaxis.set_major_locator(locator)
ax.xaxis.set_major_formatter(formatter)
fig.autofmt_xdate()

ax.yaxis.set_major_locator(MultipleLocator(2.5))

""" plt.xticks(rotation=90) """


plt.plot(data_bit['Federal Funds Target Rate'] , 'y--' , label='минимум')

""" plt.ylim(0,10) """

""" plt.xlim(1,500) """

plt.xlabel('year')
plt.ylabel('interests')

plt.show()

