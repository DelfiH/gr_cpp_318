#include <iostream>
#include "type_cast.h"

void demonstrate_type_cast() {
    // Объявление переменных
    int x = 10;
    float y = 5.5f;
    double z = 20.3;
    unsigned short k = 7;

    // 1) int i = (x + y) * z + k;
    // Явное преобразование типов
    int i_static_cast = static_cast<int>((x + y) * z) + static_cast<int>(k);
    // Неявное преобразование типов
    int i_implicit = (x + y) * z + k;

    // 2) k = x - y / z;
    // Явное преобразование типов
    k = static_cast<unsigned short>(x - static_cast<int>(y / z));
    // Неявное преобразование типов
    k = x - y / z;

    // 3) z = x * y + z / x;
    // Явное преобразование типов
    z = static_cast<double>(x * y) + static_cast<double>(z / x);
    // Неявное преобразование типов
    z = x * y + z / x;

    // 4) unsigned int ui = x / y + k;
    // Явное преобразование типов
    unsigned int ui_static_cast = static_cast<unsigned int>(x / y) + static_cast<unsigned int>(k);
    // Неявное преобразование типов
    unsigned int ui_implicit = x / y + k;

    // 5) short s = x % static_cast<int>(x / y);
    // Явное преобразование типов
    short s_static_cast = static_cast<short>(x % static_cast<int>(x / y));
    // Неявное преобразование типов
    short s_implicit = x % static_cast<int>(x / y);

    // Вывод результатов
    std::cout << "Явное (static_cast):" << std::endl;
    std::cout << "i = " << i_static_cast << std::endl;
    std::cout << "k = " << static_cast<unsigned short>(k) << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "ui = " << ui_static_cast << std::endl;
    std::cout << "s = " << s_static_cast << std::endl;

    std::cout << "\nНеявное (подразумевающееся):" << std::endl;
    std::cout << "i = " << i_implicit << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "ui = " << ui_implicit << std::endl;
    std::cout << "s = " << s_implicit << std::endl;
}
