import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

import matplotlib.pyplot as plt

X = np.linspace(-5, 5, num=100)[:, None]
y = -0.5 + 2.2*X +0.3*X**3+ 2*np.random.randn(100, 1)

print(X.shape)
plt.plot(X, y)
plt.show()
#X.shape

model = LinearRegression()
poly = PolynomialFeatures(degree=3, include_bias=False)

X_new = poly.fit_transform(X)
#X_new = X
#print(y[:85])
print(X_new.shape)

model.fit(X_new[:85], y[:85])
#LinearRegression(copy_X=True, fit_intercept=True, n_jobs=1)
y_pred = model.predict(X_new[85:])
plt.scatter(X, y)
plt.plot(X[85:], y_pred, 'r')
plt.show()


print(model.intercept_)
print(model.coef_)
X1 = np.linspace(-5, 5, num=100)[:, None]
y1 = model.intercept_ + model.coef_[0][0]*X +model.coef_[0][1]*X**2+model.coef_[0][2]*X**3
#y1 = model.intercept_ + model.coef_[0][0]*X

plt.scatter(X, y)
plt.plot(X1, y1, 'r')
plt.show()