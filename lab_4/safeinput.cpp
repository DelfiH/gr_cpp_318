#include "safeinput.h"
#include <sstream>

// Функция для безопасного ввода целого числа с проверкой
int safeInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> value && ss.eof()) {
            break;
        } else {
            std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите целое число.\n";
        }
    }
    return value;
}
