import pandas as pd
import matplotlib.pyplot as plt

import math
import numpy as np 

'''
X = []
Y = []


for x in np.arange(0 , 100, math.pi/12):
    math.pi/12
    X.append(x)
    Y.append(math.sin(x))


plt.plot(X, Y)
plt.show()
'''

X = np.linspace(0 , 100, 1000)
plt.plot(X, np.sin(X))
plt.ylim(-2, 5)
plt.show()