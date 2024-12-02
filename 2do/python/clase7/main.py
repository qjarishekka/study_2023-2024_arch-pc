import pandas as pd
from random import random

data=pd.read_csv('C:\\work\\mirepositorio\\2do\\python\\clase7\\crypto-markets.csv')
data_bit = data[['open','low','high','close']][:1000]

class Model:
    def __init__(self,koefs):
        self.koefs=koefs
    def pred(self,x):
        return self.koefs[0] * x[0] + self.koefs[1] * x[1] + self.koefs[2] * x[2]
    
    def get_child(self,delta):
        child=Model([1]*3)

        for i in range(len(self.koefs)):
            child.koefs[i]=self.koefs[i] - delta + 2*delta*random()
    
        return child 

X = data_bit[['open','low','high']]
Y = data_bit['close']

def error(model,X,Y):
    err = 0
    for i, row in X.iterrows():
        predY = model.pred(list(row))
        err += Y[i] - predY
    return err/len(Y)

model = Model([0.5,0.25,0.25])
err = error(model,X,Y)

print(err)

for g in range(1,11):

    for _ in range(100):
        child=model.get_child(0.5)
        child_err=error(child,X,Y)
        if child_err < err:
            err = child_err
            best=child
    print('Best:', best.koefs, 'Err= ', err)
    model = best

