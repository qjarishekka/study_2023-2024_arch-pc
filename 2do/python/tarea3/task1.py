import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn.cluster import Birch
from sklearn.preprocessing import MinMaxScaler


data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]

plt.scatter(data['Customer_Age'], data['Total_Trans_Amt'])

escalator = MinMaxScaler().fit(data)
data = pd.read_csv(escalator.transform(data['Customer_Age','Total_Trans_Amt' ]))



plt.xlabel('Customer Age')
plt.ylabel('Total Transactions Amount')
plt.show()

