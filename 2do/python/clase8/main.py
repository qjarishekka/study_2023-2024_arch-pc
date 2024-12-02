import pandas as pd
#from sklearn.cluster import KMeans,MeanShift
from sklearn.tree import DecisionTreeClassifier as DTC
from sklearn.ensemble import RandomForestClassifier as RFC
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
from random import random

data= pd.read_csv('C:\\work\\mirepositorio\\2do\\python\\clase8\\student-por.csv', sep=';')

dataX = data[['famrel', 'freetime', 'goout' , 'Dalc' , 'Walc']]
dataX = (dataX- dataX.mean())/dataX.std()
dataY = data['health']
trainX = dataX[:500]
trainY = dataY[:500]
testX = dataX[500:]
testY = dataY[500:]


criterions= ['gini' , 'entropy' , 'log_loss']
count = [10,30,50]

best_acc = 0
best_i = -1
best_cr = -1
best_n = -1

for i in range(10):
    for cr in criterions:
        for n in count:
            model= RFC( n_estimators = n ,criterion=cr , random_state = i)
            model.fit(dataX, dataY)
            predY = model.predict(dataX)
            acc = accuracy_score(dataY,predY)
            if acc > best_acc:
                best_acc = acc
                best_cr = cr 
                best_i = i




print(best_acc, best_cr, best_i)



""" model = MeanShift(bandwidth=1)
model.fit(data[['G1','G2']]) """
#print(model.labels_)
#plt.scatter(data['G1'], data['G2'], cmap="rainbow" , c= model.labels_)
#plt.show()



plt.scatter(data['G1'],data['G2'])
plt.show()