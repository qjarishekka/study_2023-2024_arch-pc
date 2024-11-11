import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('/Users/user/work/study/2023-2024/Архитектура_компьютера/tareas/mirepositorio/2do/python/tarea2/master.csv')
data_bit = data[['year','suicides/100k pop']]

plt.plot(data_bit['suicides/100k pop'] , 'y--' , label='минимум')

plt.xlim(1987,2024)
plt.ylim(0,200)

plt.show()

