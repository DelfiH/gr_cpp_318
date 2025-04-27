#include "tasks.h"
#include <iostream>
#include <iomanip>

// Задание 4a: Факториал (итеративно и рекурсивно)
// Итеративная функция для вычисления факториала
long long factorialIterative(int n) {
    if (n < 0) {
        std::cerr << "Ошибка: Факториал отрицательного числа не определен.\n";
        return -1; // Возвращаем -1 в случае ошибки
    }
    if (n > 20) {
        std::cerr << "Предупреждение: Факториал числа больше 20 может привести к переполнению.\n";
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        if (result > LLONG_MAX / i) {
            std::cerr << "Ошибка: Переполнение при вычислении факториала.\n";
            return -1;
        }
        result *= i;
    }
    return result;
}

// Рекурсивная функция для вычисления факториала
long long factorialRecursive(int n) {
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
        long long result = factorialRecursive(n - 1);
        if (LLONG_MAX / n < result) {
            std::cerr << "Ошибка: Переполнение при вычислении факториала.\n";
            return -1;
        }
        return n * result;
    }
}

void task4a() {
    int n;
    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> n;

    long long iterativeResult = factorialIterative(n);
    if (iterativeResult != -1) {
        std::cout << "Факториал (итеративно): " << iterativeResult << std::endl;
    }

    long long recursiveResult = factorialRecursive(n);
    if (recursiveResult != -1) {
        std::cout << "Факториал (рекурсивно): " << recursiveResult << std::endl;
    }
}

// Задание 4b: Числа Фибоначчи (итеративно)
// Итеративная функция для вычисления чисел Фибоначчи
int fibonacciIterative(int n) {
    if (n < 0) {
        std::cerr << "Ошибка: Номер Фибоначчи должен быть неотрицательным.\n";
        return -1; // Возвращаем -1 в случае ошибки
    }
    if (n > 46) {
        std::cerr << "Предупреждение: Число Фибоначчи больше 46 может привести к переполнению для int.\n";
    }
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        if (INT_MAX - a < b) {
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
    int n;
    std::cout << "Введите номер числа Фибоначчи: ";
    std::cin >> n;

    int fibonacciResult = fibonacciIterative(n);
    if (fibonacciResult != -1) {
        std::cout << "Число Фибоначчи (итеративно): " << fibonacciResult << std::endl;
    }
}

void task4c() {
    int targetSum;
    std::cout << "Введите конечное число в нижней строке пирамиды: ";
    std::cin >> targetSum;

    if (targetSum <= 0) {
        std::cerr << "Ошибка: Конечное число должно быть положительным.\n";
        return;
    }

    int currentLine = 1;
    int currentSum = 1;
    int maxNumbers = 0;

    // Определяем максимальное количество чисел в строке, чтобы правильно выровнять
    while ((currentLine * (currentLine + 1) / 2) <= targetSum) {
        maxNumbers = currentLine;
        currentLine++;
    }
    currentLine = 1;

    while (currentSum <= targetSum) {
        // Вычисляем количество пробелов перед числами
        int leadingSpaces = maxNumbers - currentLine;

        //Выводим пробелы
        for (int i = 0; i < leadingSpaces; ++i) {
            std::cout << "   "; // Три пробела для каждого выравнивания
        }

        // Выводим числа от currentLine до 1
        for (int i = currentLine; i >= 1; --i) {
            std::cout << std::setw(2) << i << " ";
        }

        std::cout << std::setw(3) << currentSum << std::endl;

        currentLine++;
        currentSum = currentLine * (currentLine + 1) / 2;
    }
}
