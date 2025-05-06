from sklearn.datasets import load_diabetes
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler

from sklearn import datasets 
from sklearn import preprocessing

dataset = pd.read_csv('insurance.csv')

dataset.plot(x = 'age' , y = 'bmi' , style = 'o')

X = dataset[[]]

x_train, x_test, y_train, y_test = train_test_split(dataset,test_size= 0.25)


dataset_min_max = MinMaxScaler().fit_transform(dataset)


plt.title('age and bmi')
plt.xlabel('age')
plt.ylabel('body mass index')
plt.show()









print(dataset)


#print(dataset.data)