#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <limits>
#include <string>
#include <sstream>
#include "safeinput.h"


// Задание 5: Создание, заполнение и сортировка массива (без библиотечной функции)
void task5() {
    int type, size;

    type = safeInput("Выберите тип данных (1-char, 2-short, 3-int, 4-float, 5-double): ");
    size = safeInput("Введите количество элементов в массиве: ");

    if (size <= 0) {
        std::cerr << "Ошибка: размер массива должен быть положительным.\n";
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    switch (type) {
        case 1: {
            std::vector<char> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = 32 + std::rand() % (127 - 32); // Генерация символов от 32 до 126
            }
            std::cout << "Массив типа char:\n";
            for (char val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::vector<short> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = std::rand() % 1000; // Генерация чисел от 0 до 999
            }
            std::cout << "Массив типа short:\n";
            for (short val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::vector<int> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = std::rand() % 1000; // Генерация чисел от 0 до 999
            }
            std::cout << "Массив типа int:\n";
            for (int val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::vector<float> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = static_cast<float>(std::rand()) / RAND_MAX * 1000.0f; // Генерация чисел от 0 до 1000
            }
            std::cout << "Массив типа float:\n";
            for (float val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::vector<double> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = static_cast<double>(std::rand()) / RAND_MAX * 1000.0; // Генерация чисел от 0 до 1000
            }
            std::cout << "Массив типа double:\n";
            for (double val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        default: {
            std::cerr << "Ошибка: Некорректный тип данных.\n";
            return;
        }
    }
}
