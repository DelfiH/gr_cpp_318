#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <iostream>
#include <string>

//-----------------------------------------------------------------------------
// Определение констант для логических значений
//-----------------------------------------------------------------------------
enum class BoolValues {
    False = 0,
    True = 1
};

//-----------------------------------------------------------------------------
// Объявление класса Bruteforce
//-----------------------------------------------------------------------------
class Bruteforce {
public:
    // Конструктор
    Bruteforce();

    // Метод для запуска взлома пароля
    void run();

private:
    // Максимальная длина пароля
    int maxLength;

    // Допустимые символы для пароля
    std::string allowedChars;

    // Пароль, который нужно взломать
    std::string password;

    // Флаг, указывающий, найден ли пароль
    BoolValues found;

    // Метод для взлома пароля
    bool crackPassword(const std::string& passwordToCrack);

    // Рекурсивный метод для генерации комбинаций
    void generateCombinations(std::string current, int length);

    // Метод для проверки корректности ввода
    bool isValidInput(const std::string& input);
};

#endif // BRUTEFORCE_H
