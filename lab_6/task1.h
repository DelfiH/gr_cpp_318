#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <string>

class Bruteforce {
private:
    std::string password;              // Пароль, который нужно взломать
    int maxLength;                     // Максимальная длина пароля
    std::string allowedChars;          // Допустимые символы в пароле
    bool found;                        // Флаг, указывающий, найден ли пароль

    void generateCombinations(std::string current, int length); // Рекурсивная функция для генерации комбинаций
    bool isValidInput(const std::string& input);                 // Проверка ввода

public:
    Bruteforce();                                               // Конструктор по умолчанию
    ~Bruteforce() = default;                                    // Деструктор по умолчанию

    void run();                                                  // Метод для запуска Bruteforce
    bool crackPassword(const std::string& passwordToCrack);      // Метод для взлома пароля

    // Геттеры и сеттеры (опционально, если нужны)
    bool isFound() const { return found; }
    const std::string& getPassword() const { return password; }
    const std::string& getAllowedChars() const { return allowedChars; }
    int getMaxLength() const { return maxLength; }
    void setMaxLength(int maxLength) { this->maxLength = maxLength; }
    void setAllowedChars(const std::string& allowedChars) { this->allowedChars = allowedChars; }
};

#endif // TASK1_H
