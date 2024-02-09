
#include <iostream>
#include <ctime> // Для генерации случайных чисел
#include <cstdlib> // Для функции rand()

int main() {
    const int size = 10;
    double *arr = new double[size]; // Создание динамического массива

    // Заполнение массива случайными данными
    srand(time(nullptr)); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 100 / 10.0; // Генерация случайного числа от 0 до 9.9
    }

    // Нахождение минимального и максимального элементов
    double min = *arr; // Предполагаем, что первый элемент - минимальный
    double max = *arr; // Предполагаем, что первый элемент - максимальный
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    // Вывод на экран массива, минимального и максимального элементов
    std::cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Минимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;

    delete[] arr; // Освобождение памяти, выделенной под массив

    return 0;
}