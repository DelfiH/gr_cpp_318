#include "tasks.h"
#include <iostream>
#include <limits>
#include <type_traits>

// Type aliases для удобства и читаемости
using IndexType = std::size_t;
using CharType = char;
using IntType = int;

// Задание 3: Вывод алфавита и ASCII кодов
void task3() {
    std::cout << "Алфавит Десятичный код символа\nанглийского языка\n";
    constexpr IndexType alphabetSize = 26; // Размер английского алфавита

    // "Защита от дурака": проверка, что alphabetSize не превышает размер алфавита
    if (alphabetSize > std::numeric_limits<CharType>::max() - 'a') {
        std::cerr << "Ошибка: alphabetSize слишком велик.\n";
        return;
    }

    for (IndexType i = 0; i < alphabetSize; ++i) {
        CharType c = 'a' + static_cast<CharType>(i);
        IntType asciiCode = static_cast<IntType>(c);
        std::cout << c << " " << asciiCode << std::endl;
    }
}
