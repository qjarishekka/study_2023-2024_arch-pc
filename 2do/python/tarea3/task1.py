import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn.cluster import Birch
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split


data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]

plt.scatter(data['Customer_Age'], data['Total_Trans_Amt'])

#print(data.head())
##print(data.tail())
#print(data.dtypes)

X = data.iloc[:,[2,17]]


#print(X.head())
#y.head()


X_train, X_test = train_test_split(X, random_state=50)




escalator = MinMaxScaler().fit(X_train)

data = pd.DataFrame(escalator.transform(X_train), columns=["Customer_Age" ,"Total_Trans_Amt" ])

#print(escalator.transform(X_train))




""" data = pd.read_csv(escalator.transform(y)) """





plt.xlabel('Customer Age')
plt.ylabel('Total Transactions Amount')
plt.show()

