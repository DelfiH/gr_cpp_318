#include "task2.h"
#include <iostream>
#include <string>
#include "palindromechecker.h"

//-----------------------------------------------------------------------------
// Функция task2: проверяет, является ли введенная строка палиндромом
//-----------------------------------------------------------------------------
void task2() {
    // Создаем объект класса PalindromeChecker
    PalindromeChecker checker;

    // Переменная для хранения введенной строки
    std::string input;

    std::cout << "Введите строку (не более 17 символов, 'q' для выхода):" << std::endl;

    // Бесконечный цикл для ввода и проверки строк
    while (true) {
        // Получаем строку от пользователя
        std::getline(std::cin, input);

        // Проверяем, не ввел ли пользователь 'q' для выхода
        if (input == "q") {
            std::cout << "Выход из task2." << std::endl;
            break;
        }

        // Устанавливаем введенную строку в объект PalindromeChecker
        checker.setInputString(input);

        // Проверяем, является ли строка палиндромом
        if (checker.isPalindrome()) {
            std::cout << "Строка является палиндромом." << std::endl;
        } else {
            std::cout << "Строка не является палиндромом." << std::endl;
        }
    }
}
