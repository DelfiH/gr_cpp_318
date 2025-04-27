#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void task2() {
    // a) Единичная матрица 5x5
    const int size = 5;
    std::vector<std::vector<int>> identityMatrix(size, std::vector<int>(size, 0));

    // Заполняем единичную матрицу
    for (int i = 0; i < size; ++i) {
        identityMatrix[i][i] = 1;
    }

    // Выводим единичную матрицу в консоль
    std::cout << "Единичная матрица " << size << "x" << size << ":\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << identityMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // b) Двумерный массив (матрица) 8x8
    const int matrixSize = 8;
    std::vector<std::vector<int>> randomMatrix(matrixSize, std::vector<int>(matrixSize));

    // Заполняем матрицу псевдослучайными числами от -15 до 15
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            randomMatrix[i][j] = rand() % 31 - 15; // Генерация чисел в диапазоне [-15, 15]
        }
    }

    // Выводим матрицу в консоль
    std::cout << "\nМатрица " << matrixSize << "x" << matrixSize << " со случайными числами:\n";
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << randomMatrix[i][j] << "\t"; // Вывод с табуляцией для выравнивания
        }
        std::cout << std::endl;
    }

    // Находим сумму элементов матрицы, лежащих выше главной диагонали
    int sumAboveDiagonal = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i + 1; j < matrixSize; ++j) {
            sumAboveDiagonal += randomMatrix[i][j];
        }
    }

    // Выводим результат сложения
    std::cout << "Сумма элементов выше главной диагонали: " << sumAboveDiagonal << std::endl;
}
