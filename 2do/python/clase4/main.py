import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('C:/work/mirepositorio/2do/python/clase5/crypto-markets.csv')
print(data[['open','low', 'high' , 'close' ]][:200])
data_bit = data[['open','low', 'high' , 'close' ]][:200]
middle = (data_bit['low'] + data_bit['high'])/2

print(middle)

diff = abs(middle -data_bit['close']) 

print(diff)

print('сгммарная ошибка ' , sum(diff))

print('средняя ошибка ', sum(diff)/len(diff) )

plt.plot(data_bit['low'] , 's--')
plt.show()