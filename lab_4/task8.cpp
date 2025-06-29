#include "tasks.h"
#include <iostream>
#include <functional>
#include <limits>
#include <string>
#include <sstream>
#include <map>
#include "safeinput.h"

// Type aliases для улучшения читаемости
using int_operation = std::function<int(int, int)>;
using func_ptr = int (*)(int, int);

// Обычные функции
int andFuncPtr(int a, int b) { return a & b; }
int orFuncPtr(int a, int b) { return a | b; }
int xorFuncPtr(int a, int b) { return a ^ b; }

// Функция с указателем на функцию
int calculateWithFunctionPtr(int a, int b, func_ptr operation) {
    return operation(a, b);
}

// std::function
int calculateWithStdFunction(int a, int b, int_operation operation) {
    return operation(a, b);
}

void task8() {
    int choice, a, b;

    // Используем safeInput только один раз
    choice = safeInput("Выберите логическую функцию (1-И, 2-ИЛИ, 3-XOR): ");
    if (choice < 1 || choice > 3) {
        std::cerr << "Ошибка: неверный выбор функции.\n";
        return;
    }

    a = safeInput("Введите первое целое число: ");
    b = safeInput("Введите второе целое число: ");

    int result;

    // ?? Используем std::map для выбора функции
#ifdef USE_STD_FUNCTION
    std::map<int, int_operation> operations = {
        {1, andFuncPtr},
        {2, orFuncPtr},
        {3, xorFuncPtr}
    };
    result = calculateWithStdFunction(a, b, operations[choice]);
    std::cout << "Результат (std::function): " << result << std::endl;
#else
    std::map<int, func_ptr> operations = {
        {1, andFuncPtr},
        {2, orFuncPtr},
        {3, xorFuncPtr}
    };
    result = calculateWithFunctionPtr(a, b, operations[choice]);
    std::cout << "Результат (указатель на функцию): " << result << std::endl;
#endif
}
