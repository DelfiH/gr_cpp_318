/*
 * Лабораторная работа №7
 * Тема: "Исследование в С++ многопоточности, ошибок, отладки блоков кода в IDE Qt Creator"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "fibonacci.h"
#include "address.h"
#include "logger_task.h"
#include "Mymessage.h"
#include "mymessagetest.h"
#include "mymessageloggger.h" // Добавляем этот заголовочный файл

//-----------------------------------------------------------------------------
// Прототипы функций для каждого задания
//-----------------------------------------------------------------------------
void runFibonacciTask();
void runAddressTask();
void runLoggerTask();
void testMyMessage();

//-----------------------------------------------------------------------------
// Главная функция программы
//-----------------------------------------------------------------------------
int main() {
    int choice;

    do {
        std::cout << "\nМеню заданий:\n";
        std::cout << "1. Вычисление чисел Фибоначчи (Задание 1)\n";
        std::cout << "2. Обработка адресов (Задание 2)\n";
        std::cout << "3. Использование LoggerGuard (Задание 3)\n";
        std::cout << "4. Проверка MyMessage(задание 4)\n";
        std::cout << "5. Запуск многопоточного логгера (Задание 5)\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите задание: ";

        if (!(std::cin >> choice)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 6.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                runFibonacciTask();
                break;
            case 2:
                runAddressTask();
                break;
            case 3:
                runLoggerTask();
                break;
            case 4:
                testMyMessage();
                break;
            case 5:
                MyApplication::mymessagelogger(); // Вызываем функцию с указанием пространства имен
                break;
            case 6:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Некорректный выбор. Пожалуйста, введите число от 1 до 6.\n";
        }
    } while (choice != 6);

    return 0;
}

//-----------------------------------------------------------------------------
// Функция для вычисления чисел Фибоначчи
//-----------------------------------------------------------------------------
void runFibonacciTask() {
    int n;
    std::cout << "Введите значение n для вычисления числа Фибоначчи: ";
    std::cin >> n;

    FibonacciCalculator calculator(n);

    try {
        calculator.calculate();
    } catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
}

