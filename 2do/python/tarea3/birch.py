import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn.cluster import Birch
from sklearn.model_selection import train_test_split
from sklearn import preprocessing

data  = pd.read_csv('/Users/user/work/study/2023-2024/Архитектура_компьютера/tareas/mirepositorio/2do/python/tarea3/BankChurners.csv')[:1000]
#data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]


data.dropna(inplace=True)


X = data.iloc[:,[9,10,11,12,17]]
data['Marital_Status'] = data['Marital_Status'].replace({'Single' : 0 ,'Married' : 1 , 'Divorced' : 2 , 'Unknown' : 3 })
Y = data.iloc[:,6]


X_train, X_test, Y_train, Y_test = train_test_split(X, Y , test_size=0.5)

data = pd.DataFrame(X_train, columns=["Customer_Age" ,"Total_Trans_Amt" ])



data_min_max = preprocessing.StandardScaler().fit_transform(X_train)

#print(escalator.transform(X_train))

clusterint1 = Birch(n_clusters=3)
clusterint1.fit(data_min_max)





plt.scatter(X_test['Months_on_book'] , X_test['Total_Trans_Amt'], c=clusterint1.labels_)
plt.xlabel('Months on book')
plt.ylabel('Total Transactions Amount')
plt.show()





