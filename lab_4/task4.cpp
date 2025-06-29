#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <type_traits>
#include "safeinput.h"

// Type aliases для удобства и читаемости
using IndexType = std::size_t;
using IntType = int;
using LongLongType = long long;


// Задание 4a: Факториал (итеративно и рекурсивно)
// Итеративная функция для вычисления факториала
LongLongType factorialIterative(IntType n) {
    if (n < 0) {
        std::cerr << "Ошибка: Факториал отрицательного числа не определен.\n";
        return -1; // Возвращаем -1 в случае ошибки
    }
    if (n > 20) {
        std::cerr << "Предупреждение: Факториал числа больше 20 может привести к переполнению.\n";
    }
    LongLongType result = 1;
    for (IndexType i = 1; i <= static_cast<IndexType>(n); ++i) {
        if (result > std::numeric_limits<LongLongType>::max() / static_cast<LongLongType>(i)) {
            std::cerr << "Ошибка: Переполнение при вычислении факториала.\n";
            return -1;
        }
        result *= static_cast<LongLongType>(i);
    }
    return result;
}

// Рекурсивная функция для вычисления факториала
LongLongType factorialRecursive(IntType n) {
    if (n < 0) {
        std::cerr << "Ошибка: Факториал отрицательного числа не определен.\n";
        return -1; // Возвращаем -1 в случае ошибки
    }
    if (n > 20) {
        std::cerr << "Предупреждение: Факториал числа больше 20 может привести к переполнению.\n";
    }
    if (n == 0) {
        return 1;
    } else {
        LongLongType result = factorialRecursive(n - 1);
        if (std::numeric_limits<LongLongType>::max() / n < result) {
            std::cerr << "Ошибка: Переполнение при вычислении факториала.\n";
            return -1;
        }
        return static_cast<LongLongType>(n) * result;
    }
}

void task4a() {
    IntType n = safeInput("Введите число для вычисления факториала: ");

    LongLongType iterativeResult = factorialIterative(n);
    if (iterativeResult != -1) {
        std::cout << "Факториал (итеративно): " << iterativeResult << std::endl;
    }

    LongLongType recursiveResult = factorialRecursive(n);
    if (recursiveResult != -1) {
        std::cout << "Факториал (рекурсивно): " << recursiveResult << std::endl;
    }
}

// Задание 4b: Числа Фибоначчи (итеративно)
// Итеративная функция для вычисления чисел Фибоначчи
IntType fibonacciIterative(IntType n) {
    if (n < 0) {
        std::cerr << "Ошибка: Номер Фибоначчи должен быть неотрицательным.\n";
        return -1; // Возвращаем -1 в случае ошибки
    }
    if (n > 46) {
        std::cerr << "Предупреждение: Число Фибоначчи больше 46 может привести к переполнению для int.\n";
    }
    if (n <= 1) return n;
    IntType a = 0, b = 1, temp;
    for (IndexType i = 2; i <= static_cast<IndexType>(n); ++i) {
        if (std::numeric_limits<IntType>::max() - a < b) {
            std::cerr << "Ошибка: Переполнение при вычислении числа Фибоначчи.\n";
            return -1;
        }
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

void task4b() {
    IntType n = safeInput("Введите номер числа Фибоначчи: ");

    IntType fibonacciResult = fibonacciIterative(n);
    if (fibonacciResult != -1) {
        std::cout << "Число Фибоначчи (итеративно): " << fibonacciResult << std::endl;
    }
}

void task4c() {
    IntType targetSum = safeInput("Введите конечное число в нижней строке пирамиды: ");

    if (targetSum <= 0) {
        std::cerr << "Ошибка: Конечное число должно быть положительным.\n";
        return;
    }

    IntType currentLine = 1;
    IntType currentSum = 1;
    IntType maxNumbers = 0;

    // Определяем максимальное количество чисел в строке, чтобы правильно выровнять
    while ((currentLine * (currentLine + 1) / 2) <= targetSum) {
        maxNumbers = currentLine;
        currentLine++;
    }
    currentLine = 1;

    while (currentSum <= targetSum) {
        // Вычисляем количество пробелов перед числами
        IntType leadingSpaces = maxNumbers - currentLine;

        // Выводим пробелы
        for (IndexType i = 0; i < static_cast<IndexType>(leadingSpaces); ++i) {
            std::cout << "   "; // Три пробела для каждого выравнивания
        }

        // Выводим числа от currentLine до 1
        for (IntType i = currentLine; i >= 1; --i) {
            std::cout << std::setw(2) << i << " ";
        }

        std::cout << std::setw(3) << currentSum << std::endl;

        currentLine++;
        currentSum = currentLine * (currentLine + 1) / 2;
    }
}
