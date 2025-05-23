import numpy as np
import pandas as pd
from urllib.request import urlopen

# 1. Cargar dataset Iris (3 clases, 4 features)
url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
column_names = ['sepal_length','sepal_width','petal_length','petal_width','class']
data = pd.read_csv(urlopen(url), header=None, names=column_names)

# 2. Estandarizar los datos (media=0, std=1)
def standardize(df, feature_cols):
    X = df[feature_cols].values
    mean = X.mean(axis=0)
    std = X.std(axis=0)
    X_std = (X - mean) / std
    return X_std, mean, std

features = ['sepal_length','sepal_width','petal_length','petal_width']
X_std, mean, std = standardize(data, features)
y = data['class'].values

print(X_std)

# 3. Dividir en entrenamiento (70%) y prueba (30%)
np.random.seed(0)
indices = np.arange(X_std.shape[0])
np.random.shuffle(indices)

split_idx = int(0.7 * len(indices))
train_idx, test_idx = indices[:split_idx], indices[split_idx:]

X_train, y_train = X_std[train_idx], y[train_idx]
X_test, y_test = X_std[test_idx], y[test_idx]

# 4. Calcular núcleos (media) y matriz de covarianza para cada clase en entrenamiento
classes = np.unique(y_train)
class_means = {}
class_covs = {}

for c in classes:
    X_c = X_train[y_train == c]
    mean_c = X_c.mean(axis=0)
    cov_c = np.cov(X_c, rowvar=False) + 1e-6*np.eye(X_c.shape[1])  # regularizar matriz para invertir
    class_means[c] = mean_c
    class_covs[c] = cov_c

# Funciones para calcular distancias
def euclidean_distance(x, mean):
    return np.linalg.norm(x - mean)

def mahalanobis_distance(x, mean, cov_inv):
    diff = x - mean
    return np.sqrt(diff.T @ cov_inv @ diff)

# 5. Clasificar muestras de prueba con ambas métricas
y_pred_euc = []
y_pred_mah = []

# Precalcular inversas de covarianzas para Mahalanobis
cov_inverses = {c: np.linalg.inv(class_covs[c]) for c in classes}

for x in X_test:
    # Distancias Euclídeas a cada clase
    dist_euc = {c: euclidean_distance(x, class_means[c]) for c in classes}
    pred_euc = min(dist_euc, key=dist_euc.get)
    y_pred_euc.append(pred_euc)
    
    # Distancias Mahalanobis a cada clase
    dist_mah = {c: mahalanobis_distance(x, class_means[c], cov_inverses[c]) for c in classes}
    pred_mah = min(dist_mah, key=dist_mah.get)
    y_pred_mah.append(pred_mah)

# 6. Calcular métricas de clasificación

def accuracy(y_true, y_pred):
    return np.sum(y_true == y_pred) / len(y_true)

def confusion_matrix(y_true, y_pred, labels):
    matrix = np.zeros((len(labels), len(labels)), dtype=int)
    label_to_idx = {label: idx for idx, label in enumerate(labels)}
    for true_label, pred_label in zip(y_true, y_pred):
        i = label_to_idx[true_label]
        j = label_to_idx[pred_label]
        matrix[i,j] += 1
    return matrix

labels = classes
acc_euc = accuracy(y_test, y_pred_euc)
acc_mah = accuracy(y_test, y_pred_mah)

cm_euc = confusion_matrix(y_test, y_pred_euc, labels)
cm_mah = confusion_matrix(y_test, y_pred_mah, labels)

print("Accuracy Euclidean:", acc_euc)
print("Confusion Matrix Euclidean:\n", cm_euc)
print("\nAccuracy Mahalanobis:", acc_mah)
print("Confusion Matrix Mahalanobis:\n", cm_mah)

# 7. Comparación con clasificador simple (e.g. clasificación por la moda - baseline)

from collections import Counter
def majority_class_predictor(y_train, n_samples):
    mode = Counter(y_train).most_common(1)[0][0]
    return np.array([mode] * n_samples)

y_pred_mode = majority_class_predictor(y_train, len(y_test))
acc_mode = accuracy(y_test, y_pred_mode)
cm_mode = confusion_matrix(y_test, y_pred_mode, labels)

print("\nAccuracy Baseline (majority class):", acc_mode)
print("Confusion Matrix Baseline:\n", cm_mode)
