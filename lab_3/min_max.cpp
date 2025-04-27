#include <iostream>
#include "min_max.h"
#include <iostream>
#include "min_max.h"

// Функция для поиска максимума двух int
int find_max(int a, int b) {
    return (a > b) ? a : b;
}

// Функция для поиска минимума двух int
int find_min(int a, int b) {
    return (a < b) ? a : b;
}

// Перегрузка функции для поиска максимума двух unsigned short
unsigned short find_max(unsigned short a, unsigned short b) {
    return (a > b) ? a : b;
}

// Перегрузка функции для поиска минимума двух unsigned short
unsigned short find_min(unsigned short a, unsigned short b) {
    return (a < b) ? a : b;
}

// Перегрузка функции для поиска максимума с порогом
int find_max(int a, int b, int threshold) {
    int maximum = find_max(a, b);
    return (maximum > threshold) ? threshold : maximum;
}

// Перегрузка функции для поиска минимума с порогом
int find_min(int a, int b, int threshold) {
    int minimum = find_min(a, b);
    return (minimum < threshold) ? threshold : minimum;
}

// Функция для ввода чисел и нахождения минимума и максимума
void find_min_max() {
    int a, b;

    std::cout << "\nВведите первое число (int): ";
    std::cin >> a;
    std::cout << "\nВведите второе число (int): ";
    std::cin >> b;

    std::cout << "\nМаксимум: " << find_max(a, b) << std::endl;
    std::cout << "\nМинимум: " << find_min(a, b) << std::endl;

    unsigned short c, d;

    std::cout << "\nВведите первое число (unsigned short): ";
    std::cin >> c;
    std::cout << "\nВведите второе число (unsigned short): ";
    std::cin >> d;

    std::cout << "\nМаксимум: " << find_max(c, d) << std::endl;
    std::cout << "\nМинимум: " << find_min(c, d) << std::endl;

    int threshold;
    std::cout << "\nВведите порог ограничения: ";
    std::cin >> threshold;

    std::cout << "\nМаксимум с порогом: " << find_max(a, b, threshold) << std::endl;
    std::cout << "\nМинимум с порогом: " << find_min(a, b, threshold) << std::endl;
}
