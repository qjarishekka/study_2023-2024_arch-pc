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
    dw = -(2/N)*np.sum(x*(y-(w_* x  + b_)))
    db = -(2/N)*np.sum(y-(w_* x  + b_))
    w = w_ - (alpha*dw)
    b = b_ - (alpha*db)
    return w, b

dataset = pd.read_csv('insurance.csv')[:50]
dataset.plot(x = 'age', y = 'charges'  , style = 'o')

#dataset['sex'] = dataset['sex'].replace({'male': 0 , 'female': 1})
#dataset['smoker'] = dataset['smoker'].replace({'yes': 1 , 'no' : 0})

X = dataset[['age']]
y = dataset[['charges']]

#print(X)


x_train, x_test, y_train, y_test = train_test_split(X,y,test_size= 0.25, random_state=0)

#x_train , y_train = MinMaxScaler().fit_transform(x_train, y_train)

#x_train_scaled = MinMaxScaler().fit_transform(x_train)
#y_train_scaled = MinMaxScaler().fit_transform(y_train)


poly  = PolynomialFeatures(degree=3)

x_train = poly.fit_transform(x_train)
y_train = poly.fit_transform(y_train)
print(x_train)

#x_train_scaled_polynomial = PolynomialFeatures(degree= 3, interaction_only=False).fit_transform(x_train)
#y_train_scaled_polynomial = PolynomialFeatures(degree= 3,interaction_only=False).fit_transform(y_train)


#print(x_train)
#print(y_train_scaled_polynomial)


""" def calculate_error(y , y_):
    N = y.shape[0]
    error =np.sum((y-y_)**2)/N
    return error """
#print(x_train_scaled.size)
#print(x_train_scaled_polynomial.size)



np.random.seed(2)
w = np.random.randn(1)[0]
b = np.random.randn(1)[0]

alpha = 0.0004
nits = 40000

for i in range(nits):
    [w,b] = descending_gradient(w,b,alpha , x_train , y_train)
    #[w,b] = descending_gradient(w,b,alpha , x_train_scaled , y_train_scaled)
    y_ = calculate_model(w,b,x_train)

 


#x_predict = np.linspace(0,5 ,100)
y_regr = calculate_model(w,b,x_test)
#print(y_regr)
plt.plot(x_test,y_regr,'r')

#plt.scatter(x_predict,y_predict)
plt.plot()


plt.title('age and charges')
plt.xlabel('age')
plt.ylabel('charges')
plt.show()












#print(dataset.data)