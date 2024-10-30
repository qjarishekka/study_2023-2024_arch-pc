import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('crypto-markets.csv')
data_bit = data[['date', 'open' , 'low' , 'hight' , 'cloase']][:200]

plt.plot(data_bit['close'], 'b' , label= 'закрытие')
plt.plot(data_bit['low'] , 'y--' , label='минимум')
plt.plot(data_bit['high'], 'g--' , label='максимум')
plt.axhline(mean, color='r' , linestyle= '-', label = 'среднее') # axhline горизонтальная линия
plt.axhline(mean + std, color='r' , linestyle= '--')
plt.axhline(mean - std , color='r' , linestyle= '--')
plt.axhline(median,  color='b' , linestyle='-.' , label = 'медиана')
plt.xlabel('дни торгов')
plt.ylabel('цены $')
plt.title('рис.1. цены на биткоин за период торгов')
plt.legend()
plt.xlim(75,125)
plt.ylim(75,150)

plt.show()
