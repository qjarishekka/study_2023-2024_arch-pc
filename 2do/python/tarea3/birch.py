import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn.cluster import Birch
from sklearn.model_selection import train_test_split
from sklearn.cluster import AffinityPropagation
from sklearn import neural_network

#data  = pd.read_csv('/Users/user/work/study/2023-2024/Архитектура_компьютера/tareas/mirepositorio/2do/python/tarea3/BankChurners.csv')[:1000]
data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]


#print(data.head())
##print(data.tail())
#print(data.dtypes)

X = data.iloc[:,[2,17]]
Y = data.iloc[:,2]


X_train, X_test, Y_train, Y_test = train_test_split(X, Y)

data = pd.DataFrame(X_train, columns=["Customer_Age" ,"Total_Trans_Amt" ])



#print(escalator.transform(X_train))


clusterint1 = Birch(n_clusters=3)
clusterint1.fit(data)




clusterint2 = AffinityPropagation(random_state=None).fit(data)


classification1 = neural_network.MLPClassifier(max_iter=5000) 
classification1.fit(X_train , Y_train)








plt.scatter(data['Customer_Age'] , data['Total_Trans_Amt'], c=clusterint1.labels_)
plt.xlabel('Customer Age')
plt.ylabel('Total Transactions Amount')
plt.show()





