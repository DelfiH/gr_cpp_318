#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    std::size_t height;
    std::size_t width;
    T** data;

    // Вспомогательные функции
    T** construct(std::size_t height, std::size_t width);
    T** copy(T** destination, T** source, std::size_t height, std::size_t width);
    T** destruct(T** data, std::size_t height);

public:
    // Конструкторы
    Matrix(std::size_t height, std::size_t width);
    Matrix(const Matrix<T>& other);
    Matrix(Matrix<T>&& other) noexcept;

    // Операторы
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T>& operator=(Matrix<T>&& other) noexcept;
    T* operator[](std::size_t row);
    const T* operator[](std::size_t row) const;
    T& operator()(std::size_t row, std::size_t col);
    const T& operator()(std::size_t row, std::size_t col) const;

    // Деструктор
    ~Matrix();

    // Методы
    std::size_t getHeight() const;
    std::size_t getWidth() const;
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator*(const T& scalar) const;
    Matrix<T> operator/(const T& scalar) const;
    Matrix<T> transpose() const;

    // Дружественные функции
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& m);
    template <typename U>
    friend std::istream& operator>>(std::istream& in, Matrix<U>& m);
};

// Реализация методов класса Matrix
template <typename T>
T** Matrix<T>::construct(std::size_t height, std::size_t width) {
    T** result = new T*[height];
    for (std::size_t i = 0; i < height; ++i) {
        result[i] = new T[width]{};
    }
    return result;
}

template <typename T>
T** Matrix<T>::copy(T** destination, T** source, std::size_t height, std::size_t width) {
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            destination[i][j] = source[i][j];
        }
    }
    return destination;
}

template <typename T>
T** Matrix<T>::destruct(T** data, std::size_t height) {
    if (data != nullptr) {
        for (std::size_t i = 0; i < height; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    return nullptr;
}

template <typename T>
Matrix<T>::Matrix(std::size_t height, std::size_t width) : height(height), width(width), data(construct(height, width)) {}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : height(other.height), width(other.width), data(copy(construct(height, width), other.data, height, width)) {}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept : height(other.height), width(other.width), data(other.data) {
    other.height = 0;
    other.width = 0;
    other.data = nullptr;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        data = destruct(data, height);
        height = other.height;
        width = other.width;
        data = copy(construct(height, width), other.data, height, width);
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
    if (this != &other) {
        data = destruct(data, height);
        height = other.height;
        width = other.width;
        data = other.data;

        other.height = 0;
        other.width = 0;
        other.data = nullptr;
    }
    return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
    data = destruct(data, height);
}

template <typename T>
T* Matrix<T>::operator[](std::size_t row) {
    return data[row];
}

template <typename T>
const T* Matrix<T>::operator[](std::size_t row) const {
    return data[row];
}

template <typename T>
T& Matrix<T>::operator()(std::size_t row, std::size_t col) {
    return data[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(std::size_t row, std::size_t col) const {
    return data[row][col];
}

template <typename T>
std::size_t Matrix<T>::getHeight() const {
    return height;
}

template <typename T>
std::size_t Matrix<T>::getWidth() const {
    return width;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Matrices should be of the same dimension sizes");
    }
    Matrix<T> result(height, width);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            result(i, j) = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Matrices should be of the same dimension sizes");
    }
    Matrix<T> result(height, width);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            result(i, j) = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (width != other.height) {
        throw std::invalid_argument("Matrix a should have its width equal to matrix b height");
    }
    Matrix<T> result(height, other.width);
    for (std::size_t i = 0; i < result.getHeight(); ++i) {
        for (std::size_t j = 0; j < result.getWidth(); ++j) {
            result(i, j) = 0;
            for (std::size_t k = 0; k < width; ++k) {
                result(i, j) += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const {
    Matrix<T> result(height, width);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            result(i, j) = data[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T& scalar) const {
    Matrix<T> result(height, width);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            result(i, j) = data[i][j] / scalar;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(width, height);
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            result(i, j) = data[j][i];
        }
    }
    return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
    for (std::size_t i = 0; i < m.getHeight(); ++i) {
        for (std::size_t j = 0; j < m.getWidth(); ++j) {
            out << std::fixed << std::setprecision(2) << std::setw(7) << m(i, j);
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& m) {
    for (std::size_t i = 0; i < m.getHeight(); ++i) {
        for (std::size_t j = 0; j < m.getWidth(); ++j) {
            in >> m(i, j);
        }
    }
    return in;
}

class FileIO {
public:
    template <typename T>
    static bool writeMatrixToFile(const Matrix<T>& matrix, const std::string& filename);

    template <typename T>
    static Matrix<T> readMatrixFromFile(const std::string& filename);
};

template <typename T>
bool FileIO::writeMatrixToFile(const Matrix<T>& matrix, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << matrix.getHeight() << " " << matrix.getWidth() << std::endl;
    for (std::size_t i = 0; i < matrix.getHeight(); ++i) {
        for (std::size_t j = 0; j < matrix.getWidth(); ++j) {
            file << matrix(i, j) << " ";
        }
        file << std::endl;
    }

    file.close();
    return true;
}

template <typename T>
Matrix<T> FileIO::readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::size_t height, width;
    file >> height >> width;
    file.ignore();

    Matrix<T> matrix(height, width);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            file >> matrix(i, j);
        }
    }

    file.close();
    return matrix;
}

#endif
