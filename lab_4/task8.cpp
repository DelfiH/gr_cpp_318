#include "tasks.h"
#include <iostream>
#include <functional>

// Обычный указатель на функцию
int andFuncPtr(int a, int b) { return a & b; }
int orFuncPtr(int a, int b) { return a | b; }
int xorFuncPtr(int a, int b) { return a ^ b; }

// Функция с указателем на функцию
int calculateWithFunctionPtr(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// std::function
int calculateWithStdFunction(int a, int b, std::function<int(int, int)> operation) {
    return operation(a, b);
}

void task8() {
    int choice, a, b;
    std::cout << "Выберите логическую функцию (1-И, 2-ИЛИ, 3-XOR): ";
    std::cin >> choice;

    if (choice < 1 || choice > 3) {
        std::cerr << "Ошибка: неверный выбор функции.\n";
        return;
    }

    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;

    int result;

#ifdef USE_STD_FUNCTION
    std::function<int(int, int)> func;
    switch (choice) {
        case 1: func = andFuncPtr; break;
        case 2: func = orFuncPtr; break;
        case 3: func = xorFuncPtr; break;
    }
    result = calculateWithStdFunction(a, b, func);
    std::cout << "Результат (std::function): " << result << std::endl;
#else
    int (*funcPtr)(int, int) = nullptr;
    switch (choice) {
        case 1: funcPtr = andFuncPtr; break;
        case 2: funcPtr = orFuncPtr; break;
        case 3: funcPtr = xorFuncPtr; break;
    }
    result = calculateWithFunctionPtr(a, b, funcPtr);
    std::cout << "Результат (указатель на функцию): " << result << std::endl;
#endif
}
