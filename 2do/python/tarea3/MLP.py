import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn import neural_network
from sklearn import preprocessing

#data  = pd.read_csv('/Users/user/work/study/2023-2024/Архитектура_компьютера/tareas/mirepositorio/2do/python/tarea3/BankChurners.csv')[:1000]
data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]

#data.dropna(inplace=True)

X = data.iloc[:,[9,10,11,12,17]]
Y = data.iloc[:,2]


x_train, x_test, y_train, y_test = train_test_split(X, Y ,test_size= 0.5)

data_min_max = preprocessing.StandardScaler().fit_transform(x_train)




classification1 = neural_network.MLPClassifier(max_iter=5000) 
classification1.fit(data_min_max , y_train)
y_pred = classification1.predict(x_test)


plt.scatter(x_test['Months_on_book'] , x_test['Total_Trans_Amt'], c=y_pred)
plt.xlabel('Months_on_book')
plt.ylabel('Total_Trans_Amt')
plt.show()

