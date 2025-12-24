#include "task1.h"
#include <iostream>
#include <limits>
#include <type_traits>

//-----------------------------------------------------------------------------
// Определение констант для логических значений
//-----------------------------------------------------------------------------
enum class BoolValues {
    False = 0,
    True = 1
};

//-----------------------------------------------------------------------------
// Функция для проверки корректности ввода целого числа
//-----------------------------------------------------------------------------
template <typename T>
bool isValidInput(const std::string& input) {
    // Проверяем, что строка не пустая
    if (input.empty()) {
        return false;
    }

    // Проверяем, что все символы в строке - цифры или знак минуса в начале
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i]) && (i != 0 || input[i] != '-')) {
            return false;
        }
    }

    // Проверяем, что число можно преобразовать в нужный тип без переполнения
    try {
        size_t pos = 0;
        std::stoi(input, &pos);
        // Если преобразование прошло успешно и обработана вся строка
        return pos == input.length();
    } catch (const std::out_of_range& oor) {
        // Если произошло переполнение
        return false;
    } catch (const std::invalid_argument& ia) {
        // Если не удалось преобразовать строку в число
        return false;
    }
}

//-----------------------------------------------------------------------------
// Функция для проверки корректности ввода размера массива (неотрицательное целое число)
//-----------------------------------------------------------------------------
bool isValidArraySizeInput(const std::string& input) {
    if (!isValidInput<size_t>(input)) {
        return false;
    }

    try {
        size_t size = std::stoul(input);
        // Проверяем, что размер массива не слишком большой
        if (size > SIZE_MAX) {
            return false;
        }
    } catch (const std::out_of_range& oor) {
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------
// Функция с произвольной сигнатурой
//-----------------------------------------------------------------------------
void someFunction(int arg) {
    std::cout << "Привет из someFunction! Аргумент: " << arg << std::endl;
}

//-----------------------------------------------------------------------------
// Глобальная переменная в секции .bss (неинициализированная)
//-----------------------------------------------------------------------------
int bssVariable;

//-----------------------------------------------------------------------------
// Глобальная переменная в секции .data (инициализированная)
//-----------------------------------------------------------------------------
int dataVariable = 42;

//-----------------------------------------------------------------------------
// Функция для вывода адресов различных типов памяти
//-----------------------------------------------------------------------------
void printMemoryLocations() {
    std::cout << "--- Расположение памяти ---" << std::endl;

    // 1. Адрес функции printMemoryLocations
    std::cout << "1. Адрес функции printMemoryLocations: "
              << reinterpret_cast<void*>(printMemoryLocations) << std::endl;

    // 2. Адрес пользовательской функции
    std::cout << "2. Адрес функции someFunction: "
              << reinterpret_cast<void*>(someFunction) << std::endl;

    // 3. Переменная в стеке
    int stackVariable = 10;
    std::cout << "3. Адрес переменной stackVariable: " << &stackVariable << std::endl;

    // 4. Массив в стеке
    int stackArray[] = {1, 2, 3, 4, 5};
    std::size_t stackArraySize = sizeof(stackArray) / sizeof(stackArray[0]);
    std::cout << "4. Адреса и значения элементов массива stackArray:" << std::endl;
    for (std::size_t i = 0; i < stackArraySize; ++i) {
        std::cout << "   stackArray[" << i << "]: Адрес = " << &stackArray[i]
                  << ", Значение = " << stackArray[i] << std::endl;
    }

    // 5. Переменная в .bss
    std::cout << "5. Адрес переменной bssVariable: " << &bssVariable << std::endl;

    // 6. Переменная в .data
    std::cout << "6. Адрес переменной dataVariable: " << &dataVariable << std::endl;

    // 7. Массив в статической памяти
    static int staticArray[] = {6, 7, 8, 9, 10};
    std::size_t staticArraySize = sizeof(staticArray) / sizeof(staticArray[0]);
    std::cout << "7. Адреса и значения элементов массива staticArray:" << std::endl;
    for (std::size_t i = 0; i < staticArraySize; ++i) {
        std::cout << "   staticArray[" << i << "]: Адрес = " << &staticArray[i]
                  << ", Значение = " << staticArray[i] << std::endl;
    }

    // 8. Переменная в куче
    int* heapVariable = new int(20);
    std::cout << "8. Адрес переменной heapVariable: " << heapVariable << std::endl;

    // 9. Массив в куче с защитой от неправильного ввода
    std::size_t heapArraySize;
    std::string input;

    while (true) {
        std::cout << "9. Введите размер массива в куче: ";
        std::cin >> input;

        if (isValidArraySizeInput(input)) {
            heapArraySize = std::stoul(input);
            break;
        } else {
            std::cerr << "Некорректный ввод. Пожалуйста, введите положительное целое число." << std::endl;
        }
    }

    int* heapArray = new int[heapArraySize];

    // Инициализация массива и вывод адресов и значений
    std::cout << "Введите значения для массива в куче:" << std::endl;
    for (std::size_t i = 0; i < heapArraySize; ++i) {
        while (true) {
            std::cout << "   heapArray[" << i << "]: ";
            std::cin >> input;

            if (isValidInput<int>(input)) {
                heapArray[i] = std::stoi(input);
                break;
            } else {
                std::cerr << "Некорректный ввод. Пожалуйста, введите целое число." << std::endl;
            }
        }
    }

    std::cout << "Адреса и значения элементов массива heapArray:" << std::endl;
    for (std::size_t i = 0; i < heapArraySize; ++i) {
        std::cout << "   heapArray[" << i << "]: Адрес = " << &heapArray[i]
                  << ", Значение = " << heapArray[i] << std::endl;
    }

    // Освобождение памяти
    delete heapVariable;
    delete[] heapArray;
}

//-----------------------------------------------------------------------------
// Функция task1
//-----------------------------------------------------------------------------
void task1() {
    std::cout << "Выполнение задачи 1..." << std::endl;
    printMemoryLocations();
}
