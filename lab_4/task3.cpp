#include "tasks.h"
#include <iostream>

// Задание 3: Вывод алфавита и ASCII кодов
void task3() {
    std::cout << "Алфавит Десятичный код символа\nанглийского языка\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }
}
