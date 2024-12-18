import pandas as pd
from random import random
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.cluster import AffinityPropagation


data  = pd.read_csv('C:/work/mirepositorio/2do/python/tarea3/BankChurners.csv')[:2000]
data.dropna(inplace=True)


""" scaler = StandardScaler()

data1 = data
data1[['Credit_Limit' , 'Dependent_count']] = scaler.fit_transform(data[['Credit_Limit', 'Dependent_count']])

print(data1[['Credit_Limit' , 'Dependent_count']])

clustering = AffinityPropagation(random_state=None).fit(data1[['Credit_Limit' , 'Dependent_count']])
 """



X = data.iloc[:,[9,10,11,13,17]]
Y = data.iloc[:,2]

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.5)  

#data1 = pd.DataFrame(X_train, columns=["Customer_Age" ,"Total_Trans_Amt"])
#data1.dropna(inplace=True)


data_min_max = preprocessing.StandardScaler().fit_transform(X_train)

clusterint2 = AffinityPropagation(random_state=3).fit(data_min_max)


plt.scatter(X_test['Months_on_book'] , X_test['Total_Trans_Amt'] , c=clusterint2.labels_)
plt.xlabel('Customer Age')
plt.ylabel('Total Transactions Amount')
plt.show()


