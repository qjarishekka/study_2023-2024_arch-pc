from sklearn.datasets import load_diabetes
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import PolynomialFeatures

from sklearn import datasets 
from sklearn import preprocessing


def calculate_model(w , b , x):
    return w*x + b

def descending_gradient(w_ , b_ , alpha, x ,y):
    N = x.shape[0]
    #print(N)
    dw = -(2/N)*np.sum(x*(y-(w_* x  + b_)))
    db = -(2/N)*np.sum(y-(w_* x  + b_))
    w = w_ - alpha*dw
    b = b_ - alpha*db
    return w, b

dataset = pd.read_csv('insurance.csv')[:10]
dataset.plot(x = 'age', y = 'charges'  , style = 'o')

X = dataset[['age' ]]
y = dataset[['charges']]

x_train, x_test, y_train, y_test = train_test_split(X,y,test_size= 0.25 , shuffle=False , random_state=0)




