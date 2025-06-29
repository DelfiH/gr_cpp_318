#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <type_traits>
#include <memory>

// Type aliases для улучшения читаемости и гибкости
using IntType = int;
using FloatType = float;
using CharType = char;
using IntPtr = IntType*;
using FloatPtr = FloatType*;
using CharPtr = CharType*;
using SizeType = std::size_t; // Для счетчиков и индексов

// Функция для безопасного ввода целого числа
IntType safeIntInput(const std::string& prompt) {
    IntType value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        ss >> value;

        if (ss.fail()) {
            std::cout << "Ошибка: некорректный ввод. Пожалуйста, введите целое число.\n";
            ss.clear(); // <--- Очищаем состояние ошибки
            continue; // Повторяем ввод
        }
        else {
            char remaining;
            if (ss >> remaining) {
                std::cout << "Ошибка: после числа обнаружены лишние символы. Пожалуйста, "
                    "введите только целое число.\n";
            }
            else {
                break; // Ввод успешен, выходим из цикла
            }
        }
    }
    return value;
}
FloatType safeFloatInput(const std::string& prompt) {
    FloatType value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty()) { // Проверка на пустой ввод
            std::cout << "Ошибка: пустой ввод. Пожалуйста, введите число с плавающей точкой.\n";
            continue;
        }

        std::stringstream ss(input);
        ss >> value;

        if (ss.fail()) {
            std::cout << "Ошибка: некорректный ввод. Пожалуйста, введите число с плавающей точкой.\n";
            ss.clear();
            continue;
        }
        // Проверка на наличие лишних символов
        char remaining;
        if (ss.get(remaining)) {
            std::cout << "Ошибка: после числа обнаружены лишние символы. Пожалуйста, введите только число с плавающей точкой.\n";
            ss.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // "Съедаем" все лишние символы
        } else {
            break; // Ввод успешен
        }
    }
    return value;
}
// Функция для безопасного ввода символа
CharType safeCharInput(const std::string& prompt) {
    CharType ch;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.length() == 1) {
            ch = input[0];
            break;
        }
        else {
            std::cout << "Ошибка: некорректный ввод. Пожалуйста, введите один символ.\n";
        }
    }
    return ch;
}

void task6a() {
    IntType m;
    FloatType fx;
    CharType cht;

    std::cout << "Указатель: продемонстрировать использование операторов & и *\n";
    std::cout << "------------------------------------------------------\n";

    m = safeIntInput("Введите целое число m: ");

    fx = safeFloatInput("Введите число с плавающей точкой fx: ");

    cht = safeCharInput("Введите символ cht: ");

    std::cout << "m = " << m << std::endl;
    std::cout << "fx = " << fx << std::endl;
    std::cout << "cht = " << cht << std::endl;

    std::cout << "\nИспользование & оператор:\n";
    std::cout << "----------------------\n";
    std::cout << "адрес m = " << &m << std::endl;
    std::cout << "адрес fx = " << &fx << std::endl;
    std::cout << "адрес cht = " << &cht << std::endl;

    std::cout << "\nИспользуя операторы & и *:\n";
    std::cout << "-----------------------------\n";
    std::cout << "значение по адресу m = " << *(&m) << std::endl;
    std::cout << "значение по адресу fx = " << *(&fx) << std::endl;
    std::cout << "значение по адресу cht = " << *(&cht) << std::endl;

    std::cout << "\nИспользуя только переменную указателя:\n";
    std::cout << "----------------------------------\n";
    IntPtr ptr_m = &m;
    FloatPtr ptr_fx = &fx;
    CharPtr ptr_cht = &cht;

    std::cout << "адрес m = " << ptr_m << std::endl;
    std::cout << "адрес fx = " << ptr_fx << std::endl;
    std::cout << "адрес cht = " << ptr_cht << std::endl;

    std::cout << "\nИспользование только оператора указателя:\n";
    std::cout << "----------------------------------\n";
    std::cout << "значение по адресу m = " << *ptr_m << std::endl;
    std::cout << "значение по адресу fx = " << *ptr_fx << std::endl;
    std::cout << "значение по адресу cht = " << *ptr_cht << std::endl;
}

void task6b() {
    IntType n = safeIntInput("Введите количество элементов в массиве: ");

    if (n <= 0) {
        std::cerr << "Ошибка: размер массива должен быть положительным.\n";
        return;
    }

    std::unique_ptr<IntType[]> arr(new IntType[n]); // Используем unique_ptr

    std::cout << "Введите элементы массива:\n";
    for (SizeType i = 0; i < static_cast<SizeType>(n); ++i) {
        arr[i] = safeIntInput("Элемент " + std::to_string(i + 1) + ": ");
    }

    std::cout << "Элементы массива, напечатанные с помощью указателя:\n";
    IntType* ptr = arr.get(); // Получаем "сырой" указатель из unique_ptr
    for (SizeType i = 0; i < static_cast<SizeType>(n); ++i) {
        std::cout << "arr[" << i << "] = " << *ptr << " (адрес: " << static_cast<void*>(ptr) << ")\n";
        ++ptr; // Перемещаем указатель на следующий элемент
    }

    // Память будет освобождена автоматически при выходе из области видимости
}
