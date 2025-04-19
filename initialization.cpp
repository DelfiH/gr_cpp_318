#include <iostream>
#include "initialization.h"

// Глобальная переменная
int iValue = 10;

// Функция для демонстрации различных типов инициализации
void demonstrate_initialization() {
    // Копирующая инициализация
    int copyInit = iValue;

    // Прямая инициализация
    int directInit(20);

    // Унифицированная инициализация
    int uniformInit{30};

    // Авто-инициализация
    auto autoInit = 40;

    // Вывод значений
    std::cout << "\nКопирующая инициализация: " << copyInit << std::endl;
    std::cout << "\nПрямая инициализация: " << directInit << std::endl;
    std::cout << "\nУнифицированная инициализация: " << uniformInit << std::endl;
    std::cout << "\nАвто-инициализация: " << autoInit << std::endl;

    // Инициализация других типов
    bool bValue{true};
    char cValue{'A'};
    long lValue{123456789L};

    std::cout << "\niValue: " << iValue << std::endl;
    std::cout << "\nBValue: " << bValue << std::endl;
    std::cout << "\nCValue: " << cValue << std::endl;
    std::cout << "\nLValue: " << lValue << std::endl;
}
