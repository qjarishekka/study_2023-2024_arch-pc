import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures, StandardScaler

class LinearRegression:


    def __init__(self, x , y , method = "analytic" , alpha = 0.01, nits = 1000):
        self.method = method

        #usando el metodo de busqueda de gradiente
        if method=="gradient" :
            #aplanamos la matriz y para evitar problemas
            y = y.ravel()
            #obtenemos la forma de la matrix X
            n_samples , n_features = x.shape
            #formamos un arreglo de ceros con n componentes
            self.w = np.zeros(n_features)
            #damos un valor inicial a B
            self.b = 0

            #iniciamos las interaciones
            for i in range(nits):
                #multiplicamos las matrices y sumamos b (formula: X*w + b)
                y_pred = x @ self.w + self.b
                #guardamos los errores
                error = y_pred - y
                #calculamos la gradiente de la funcion de perdida respecto a los pesos
                dw = (2/n_samples) * (x.T @ error)
                #calculamos la gradiente de la funcion de perdida respecto al sesgo b
                db = (2/n_samples) * np.sum(error)

                #actualizamos los parametros con un paso de alpha en cada interaccion
                self.w -= alpha * dw
                self.b -= alpha*db
                #imprimimos el error
                if i % 100 == 0 :
                    loss = np.mean(error **2)
                    print("loss: ", loss)
            
        #metodo analitico
        else:
            X_bias = np.hstack((np.ones((x.shape[0],1)), x))
            #calculamos la solucion analitica para los coeficientes
            # usando la pseudo inversa de Moore-Penrose 
            # formulas: w = ( (X^t * X)^(-1) ) * (X^t)*y 
            #      *se uso esta*    w = pinv(X^t * X) * (X^t) *y
            # X_bias.T @ X_bias : genera una matriz normal
            # .pinv() : calcula la pseudoinversa
            self.coefficients = np.linalg.pinv(X_bias.T @ X_bias) @ X_bias.T @ y




    def predict(self, x):
        #calculamos la prediccion
        if self.method == "gradient":
            return x @ self.w + self.b

        else:
            X_bias = np.hstack((np.ones((x.shape[0],1)),x))
            return X_bias @ self.coefficients

        
        





class PolinomialRegression:
    def __init__(self, x, y, method="", alpha=0.0001, nits=1000):
        #aplanamos la matriz
        y = y.ravel()

        self.X_poly = x
        #metodo de gradiente
        if method == "gradient":
            #guaramos la forma
            n_s, n_f = self.X_poly.shape
            #creamos una matriz inicial de ceros
            w = np.zeros(n_f)
            #interacciones
            for epoch in range(nits):
                #multiplicamos las matrices x y w
                y_pred = self.X_poly @ w
                #calculamos el error
                error = y_pred - y
                #calculamos la gradiente
                grad = 2 * self.X_poly.T @ error / n_s
                #actualizamos los pesos
                w -= alpha * grad
                #imprimimios los pesos
                if epoch % 100 == 0:
                    loss = np.mean(error ** 2)
                    print(f"Epoch {epoch} - Loss: {loss:.4f}")
            self.coefficients = w
        #metodo analitico
        else:
            #self.X_poly.T @ self.X_poly : calculamos la matriz de correlacion entre las caracteristicas polinomicas
            #.pinv: calulamos la psudoinversa
            # @ self.X_poly.T @ y: terminamos de hallar 

            self.coefficients = np.linalg.pinv(self.X_poly.T @ self.X_poly) @ self.X_poly.T @ y

    def predict(self, x):
        return x @ self.coefficients


# Cargar dataset
numberOfSamples = 100
x_column = "age"
y_column = "daily_social_media_time"

dataset = pd.read_csv('social_media_vs_productivity.csv')[:numberOfSamples]
dataset = dataset.dropna().drop_duplicates()

X = dataset[[x_column]].values
y = dataset[[y_column]].values

# Separar datos
x_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.25, shuffle=False, random_state=0)

# Normalizar
scaler = StandardScaler()
x_train_scaled = scaler.fit_transform(x_train)

# Aplicar expansión polinómica externa (grado 3)
poly = PolynomialFeatures(degree=3, include_bias=False)
x_train_poly = poly.fit_transform(x_train_scaled)


rlAnalitic = LinearRegression(x=x_train_poly , y=y_train)
rlGradient = LinearRegression(x=x_train_poly, y=y_train, method="gradient")


# Entrenar modelo polinomial
prAnalitic = PolinomialRegression(x=x_train_poly, y=y_train)
prGradient = PolinomialRegression(x=x_train_poly, y=y_train, method="gradient")

# Predicción sobre nuevo conjunto de valores
X1 = np.linspace(X.min(), X.max(), num=numberOfSamples)[:, None]
X1_scaled = scaler.transform(X1)
X1_poly = poly.transform(X1_scaled)

Y1 = rlAnalitic.predict(X1_poly)
Y2 = rlGradient.predict(X1_poly)
Y3 = prAnalitic.predict(X1_poly)
Y4 = prGradient.predict(X1_poly)


# Gráfico
plt.scatter(x_train, y_train, color='blue', label='Datos')
plt.plot(X1, Y1, 'b', label='Lineal Analitic')
plt.plot(X1, Y2, 'y', label='Lineal Gradient')
plt.plot(X1, Y3, 'g', label='Polinomial Analitic (grado 3)')
plt.plot(X1, Y4, 'r', label='Polinomial Gradient (grado 3)')
plt.title('Regresión Polinómica')
plt.xlabel(x_column)
plt.ylabel(y_column)
plt.legend()
plt.grid(True)
plt.show()
