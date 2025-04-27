#include "tasks.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>

// Функция для генерации псевдослучайных чисел в заданном диапазоне (собственная реализация)
int generateRandom(int minVal, int maxVal) {
    static std::random_device rd;  // Статическое для инициализации только один раз
    static std::mt19937 gen(rd()); // Статическое для инициализации только один раз
    std::uniform_int_distribution<> distrib(minVal, maxVal);
    return distrib(gen);
}

// Задание 1: Работа с массивом случайных чисел
void task1() {
    const int arraySize = 10;
    std::vector<int> arr(arraySize);
    int minRange, maxRange;

    std::cout << "Введите минимальное значение диапазона: ";
    std::cin >> minRange;

    std::cout << "Введите максимальное значение диапазона: ";
    std::cin >> maxRange;

    if (minRange >= maxRange) {
        std::cerr << "Ошибка: Минимальное значение должно быть меньше максимального.\n";
        return;
    }

    // 1. Заполнение массива с использованием библиотечного алгоритма (Вихрь Мерсенна)
    std::cout << "\nИспользование библиотечного алгоритма (Вихрь Мерсенна):\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minRange, maxRange);

    for (int i = 0; i < arraySize; ++i) {
        arr[i] = distrib(gen);
    }

    std::cout << "Значения элементов массива (алгоритм):\n";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Поиск минимума и максимума (используем алгоритмы STL)
    auto minMax = std::minmax_element(arr.begin(), arr.end());
    int minVal = *minMax.first;
    int maxVal = *minMax.second;

    std::cout << "Минимальное значение массива: " << minVal << std::endl;
    std::cout << "Максимальное значение массива: " << maxVal << std::endl;

    // 2. Заполнение массива с использованием собственной реализации ГПСЧ
    std::cout << "\nИспользование собственной реализации ГПСЧ:\n";
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = generateRandom(minRange, maxRange);
    }

    std::cout << "Значения элементов массива (собственная реализация):\n";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Поиск минимума и максимума (используем алгоритмы STL)
    minMax = std::minmax_element(arr.begin(), arr.end());
    minVal = *minMax.first;
    maxVal = *minMax.second;

    std::cout << "Минимальное значение массива: " << minVal << std::endl;
    std::cout << "Максимальное значение массива: " << maxVal << std::endl;
}
