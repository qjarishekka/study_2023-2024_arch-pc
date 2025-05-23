import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split

class Classification:
    def __init__(self, X, y):
        self.y_true = y
        self.classes = np.unique(y)
        self.class_means = {}
        self.class_covs = {}

        for c in self.classes:
            X_c = X[y == c]
            mean_c = X_c.mean(axis=0)
            cov_c = np.cov(X_c, rowvar=False) + 1e-6 * np.eye(X_c.shape[1])
            self.class_means[c] = mean_c
            self.class_covs[c] = cov_c

        self.cov_inverses = {c: np.linalg.inv(self.class_covs[c]) for c in self.classes}
        self.y_pred_euclidean = []
        self.y_pred_mahalanobis = []

    def euclidean_distance(self, x, mean):
        return np.linalg.norm(x - mean)

    def mahalanobis_distance(self, x, mean, cov_inv):
        diff = x - mean
        return np.sqrt(diff.T @ cov_inv @ diff)

    @staticmethod
    def accuracy(y_true, y_pred):
        return np.sum(y_true == y_pred) / len(y_true)

    @staticmethod
    def confusion_matrix(y_true, y_pred, labels):
        matrix = np.zeros((len(labels), len(labels)), dtype=int)
        label_to_idx = {label: idx for idx, label in enumerate(labels)}
        for true_label, pred_label in zip(y_true, y_pred):
            i = label_to_idx[true_label]
            j = label_to_idx[pred_label]
            matrix[i, j] += 1
        return matrix

    def predict(self, X, y_test):
        for x in X:
            dist_euc = {c: self.euclidean_distance(x, self.class_means[c]) for c in self.classes}
            pred_euc = min(dist_euc, key=dist_euc.get)
            self.y_pred_euclidean.append(pred_euc)

            dist_mah = {c: self.mahalanobis_distance(x, self.class_means[c], self.cov_inverses[c]) for c in self.classes}
            pred_mah = min(dist_mah, key=dist_mah.get)
            self.y_pred_mahalanobis.append(pred_mah)

        self.accuracy_euclidean = self.accuracy(y_test, self.y_pred_euclidean)
        self.accuracy_mahalanobis = self.accuracy(y_test, self.y_pred_mahalanobis)

        self.confusion_matrix_euclidean = self.confusion_matrix(y_test, self.y_pred_euclidean, self.classes)
        self.confusion_matrix_mahalanobis = self.confusion_matrix(y_test, self.y_pred_mahalanobis, self.classes)


def standardize(X):
    mean = X.mean(axis=0)
    std = X.std(axis=0)
    X_std = (X - mean) / std
    return X_std


# Cargar y preparar datos
url = "iris.data"
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'Class']
dataset = pd.read_csv(url, names=names)

X = dataset[['sepal-length', 'sepal-width', 'petal-length', 'petal-width']].values
y = dataset['Class'].values

X_scaled = standardize(X)
x_train, x_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.25, shuffle=False, random_state=0)

# Clasificación
classifier = Classification(x_train, y_train)
classifier.predict(x_test, y_test)

# Mostrar resultados
print("predictions euclidean: ", classifier.y_pred_euclidean)
print("predictions mahalanobis: ", classifier.y_pred_mahalanobis)

print("Accuracy Euclidean:", classifier.accuracy_euclidean)
print("Confusion Matrix Euclidean:\n", classifier.confusion_matrix_euclidean)

print("\nAccuracy Mahalanobis:", classifier.accuracy_mahalanobis)
print("Confusion Matrix Mahalanobis:\n", classifier.confusion_matrix_mahalanobis)


from sklearn.neighbors import KNeighborsClassifier

knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(x_train, y_train)
knn_preds = knn.predict(x_test)

knn_accuracy = np.sum(knn_preds == y_test) / len(y_test)
print("\nAccuracy KNN (sklearn):", knn_accuracy)