#include "matrix.h"
#include <iostream>
#include <random>

// Функция для генерации случайных значений в диапазоне [1, 256]
template <typename T>
Matrix<T> generateRandomMatrix(std::size_t height, std::size_t width) {
    Matrix<T> matrix(height, width);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 256);

    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            matrix(i, j) = distrib(gen);
        }
    }

    return matrix;
}

void matrixMenu() {
    // Пример использования класса Matrix
    Matrix<int> matrix1(2, 3);
    matrix1(0, 0) = 1;
    matrix1(0, 1) = 2;
    matrix1(0, 2) = 3;
    matrix1(1, 0) = 4;
    matrix1(1, 1) = 5;
    matrix1(1, 2) = 6;

    std::cout << "Matrix 1:\n" << matrix1 << std::endl;

    Matrix<int> matrix2(3, 2);
    matrix2(0, 0) = 7;
    matrix2(0, 1) = 8;
    matrix2(1, 0) = 9;
    matrix2(1, 1) = 10;
    matrix2(2, 0) = 11;
    matrix2(2, 1) = 12;

    std::cout << "Matrix 2:\n" << matrix2 << std::endl;

    // Пример умножения матриц
    Matrix<int> matrix3 = matrix1 * matrix2;
    std::cout << "Matrix 1 * Matrix 2:\n" << matrix3 << std::endl;

    // Пример сложения матриц
    Matrix<int> matrix4(2, 3);
    matrix4(0, 0) = 13;
    matrix4(0, 1) = 14;
    matrix4(0, 2) = 15;
    matrix4(1, 0) = 16;
    matrix4(1, 1) = 17;
    matrix4(1, 2) = 18;

    Matrix<int> matrix5 = matrix1 + matrix4;
    std::cout << "Matrix 1 + Matrix 4:\n" << matrix5 << std::endl;

    // Пример умножения матрицы на скаляр
    Matrix<int> matrix6 = matrix1 * 2;
    std::cout << "Matrix 1 * 2:\n" << matrix6 << std::endl;

    // Пример транспонирования матрицы
    Matrix<int> matrix7 = matrix1.transpose();
    std::cout << "Transpose of Matrix 1:\n" << matrix7 << std::endl;

    // Пример использования FileIO для записи и чтения матрицы из файла
    FileIO::writeMatrixToFile(matrix1, "matrix1.txt");
    Matrix<int> matrix8 = FileIO::readMatrixFromFile<int>("matrix1.txt");
    std::cout << "Matrix read from file:\n" << matrix8 << std::endl;

    // Пример генерации случайной матрицы
    Matrix<int> randomMatrix = generateRandomMatrix<int>(3, 4);
    std::cout << "Random Matrix:\n" << randomMatrix << std::endl;
}
