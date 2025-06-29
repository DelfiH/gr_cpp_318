#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

void task2() {
    // a) Единичная матрица 5x5
    const std::size_t size = 5;
    if (size == 0) {
        std::cerr << "Ошибка: Размер матрицы не может быть равен нулю.\n";
        return;
    }
    std::vector<std::vector<int>> identityMatrix(size, std::vector<int>(size, 0));

    // Заполняем единичную матрицу
    for (std::size_t i = 0; i < size; ++i) {
        identityMatrix[i][i] = 1;
    }

    // Выводим единичную матрицу в консоль
    std::cout << "Единичная матрица " << size << "x" << size << ":\n";
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            std::cout << identityMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // b) Двумерный массив (матрица) 8x8
    const std::size_t matrixSize = 8;
    if (matrixSize == 0) {
        std::cerr << "Ошибка: Размер матрицы не может быть равен нулю.\n";
        return;
    }
    std::vector<std::vector<int>> randomMatrix(matrixSize, std::vector<int>(matrixSize));

    // Заполняем матрицу псевдослучайными числами от -15 до 15
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Инициализация генератора случайных чисел
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = 0; j < matrixSize; ++j) {
            randomMatrix[i][j] = std::rand() % 31 - 15; // Генерация чисел в диапазоне [-15, 15]
        }
    }

    // Выводим матрицу в консоль
    std::cout << "\nМатрица " << matrixSize << "x" << matrixSize << " со случайными числами:\n";
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = 0; j < matrixSize; ++j) {
            std::cout << randomMatrix[i][j] << "\t"; // Вывод с табуляцией для выравнивания
        }
        std::cout << std::endl;
    }

    // Находим сумму элементов матрицы, лежащих выше главной диагонали
    long long sumAboveDiagonal = 0;
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = i + 1; j < matrixSize; ++j) {
            sumAboveDiagonal += randomMatrix[i][j];
            // Проверка на переполнение (опционально)
            if (sumAboveDiagonal > std::numeric_limits<int>::max()) {
                std::cerr << "Предупреждение: Сумма элементов выше главной диагонали может привести к переполнению.\n";
            }
        }
    }

    // Выводим результат сложения
    std::cout << "Сумма элементов выше главной диагонали: " << sumAboveDiagonal << std::endl;
}
