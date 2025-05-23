import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

class LinearRegressionAnalytical:
    def __init__(self):
        self.coefficients = None

    def fit(self, X, y):
        # Añadir columna de 1s para el sesgo (intercepto)
        X_bias = np.hstack((np.ones((X.shape[0], 1)), X))
        # Cálculo analítico: θ = (XᵀX)^(-1) Xᵀy
        self.coefficients = np.linalg.pinv(X_bias.T @ X_bias) @ X_bias.T @ y

    def predict(self, X):
        X_bias = np.hstack((np.ones((X.shape[0], 1)), X))
        return X_bias @ self.coefficients

# ===============================
# Cargar dataset desde CSV
# ===============================

# Ajusta aquí los nombres según tu archivo
csv_file = 'social_media_vs_productivity.csv'
x_column = 'age'
y_column = 'daily_social_media_time'

# Leer datos
data = pd.read_csv(csv_file)[:100].dropna().drop_duplicates()

# Convertir a arrays
X = data[[x_column]].values  # 2D matriz
y = data[[y_column]].values  # 2D matriz para mantener forma compatible

# Entrenar modelo
model = LinearRegressionAnalytical()
model.fit(X, y)

# Predecir
X_line = np.linspace(X.min(), X.max(), 100).reshape(-1, 1)
y_pred = model.predict(X_line)

# ===============================
# Visualización
# ===============================
plt.scatter(X, y, color='blue', label='Datos reales')
plt.plot(X_line, y_pred, color='red', label='Regresión lineal')
plt.title('Regresión Lineal (Analítica)')
plt.xlabel(x_column)
plt.ylabel(y_column)
plt.legend()
plt.grid(True)
plt.show()
