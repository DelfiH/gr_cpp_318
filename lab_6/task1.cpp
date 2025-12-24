#include "bruteforce.h"
#include <iostream>

//-----------------------------------------------------------------------------
// Конструктор класса Bruteforce по умолчанию
//-----------------------------------------------------------------------------
Bruteforce::Bruteforce() : maxLength(0), allowedChars(""), found(BoolValues::False) {}

//-----------------------------------------------------------------------------
// Метод для запуска Bruteforce
//-----------------------------------------------------------------------------
void Bruteforce::run() {
    std::string passwordToCrack;

    std::cout << "Введите максимальную длину пароля: ";
    std::cin >> maxLength;

    std::cout << "Введите допустимые символы для пароля: ";
    std::cin >> allowedChars;

    std::cout << "Введите пароль для взлома: ";
    std::cin >> passwordToCrack;

    crackPassword(passwordToCrack);
}

//-----------------------------------------------------------------------------
// Метод для взлома пароля
//-----------------------------------------------------------------------------
bool Bruteforce::crackPassword(const std::string& passwordToCrack) {
    password = passwordToCrack;
    found = BoolValues::False;

    if (!isValidInput(password)) {
        std::cout << "Ошибка: Некорректный ввод пароля." << std::endl;
        return false;
    }

    std::cout << "Перебор всех возможных комбинаций..." << std::endl;
    for (int len = 1; len <= maxLength; ++len) {
        generateCombinations("", len);
        if (found == BoolValues::True) {
            break; // Если пароль найден, прерываем цикл
        }
    }

    if (found == BoolValues::True) {
        std::cout << "Пароль найден: " << password << std::endl;
    } else {
        std::cout << "Пароль не найден." << std::endl;
    }

    return (found == BoolValues::True);
}

//-----------------------------------------------------------------------------
// Рекурсивная функция для генерации всех возможных комбинаций символов
//-----------------------------------------------------------------------------
void Bruteforce::generateCombinations(std::string current, int length) {
    if (found == BoolValues::True) {
        return; // Если пароль уже найден, выходим из рекурсии
    }

    if (length == 0) {
        // Если длина комбинации достигла 0, проверяем, совпадает ли она с паролем
        if (current == password) {
            std::cout << "Пароль найден: " << current << std::endl;
            found = BoolValues::True;
        }
        return;
    }

    // Рекурсивно вызываем функцию для каждой возможной буквы
    for (char c : allowedChars) {
        generateCombinations(current + c, length - 1);
    }
}

//-----------------------------------------------------------------------------
// Проверяет, что введенный пароль соответствует допустимым символам и длине
//-----------------------------------------------------------------------------
bool Bruteforce::isValidInput(const std::string& input) {
    if (input.length() > static_cast<unsigned long>(maxLength)) {
        std::cout << "Ошибка: Длина пароля превышает максимальную длину (" << maxLength << ")." << std::endl;
        return false;
    }

    for (char c : input) {
        if (allowedChars.find(c) == std::string::npos) {
            std::cout << "Ошибка: Пароль содержит недопустимый символ." << std::endl;
            return false;
        }
    }

    return true;
}
