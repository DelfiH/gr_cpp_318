#include <iostream>
#include <string>
#include <algorithm>
#include "extratask1.h"

using namespace std;

//-----------------------------------------------------------------------------
// Функция для преобразования целого числа в строку с использованием степеней 10
// и визуализацией разложения
//-----------------------------------------------------------------------------
string intToStringPow10(int num) {
    // Таблица степеней 10 для 32-битных чисел
    const unsigned int pow10Table32[] = {
        1000000000ul,  // 10^9
        100000000ul,   // 10^8
        10000000ul,    // 10^7
        1000000ul,     // 10^6
        100000ul,      // 10^5
        10000ul,       // 10^4
        1000ul,        // 10^3
        100ul,         // 10^2
        10ul,          // 10^1
        1ul            // 10^0
    };

    // Если число равно 0, возвращаем "0"
    if (num == 0) {
        return "0";
    }

    string result = "";    // Результирующая строка
    bool isNegative = false; // Флаг отрицательного числа
    string visualRepresentation = ""; // Визуальное представление разложения

    // Проверяем, является ли число отрицательным
    if (num < 0) {
        isNegative = true;  // Устанавливаем флаг отрицательного числа
        num = -num;         // Берем абсолютное значение числа
    }

    // Преобразуем число в строку, используя степени 10
    for (int i = 0; i < 10; ++i) {
        int digit = num / pow10Table32[i]; // Вычисляем цифру
        if (digit > 0 || !visualRepresentation.empty()) {
            if (!visualRepresentation.empty()) {
                visualRepresentation += " + ";
            }
            visualRepresentation += to_string(digit) + "*" + to_string(pow10Table32[i]);
        }
        result += digit + '0';              // Добавляем цифру к результату
        num %= pow10Table32[i];              // Обновляем число
    }

    // Удаляем ведущие нули
    size_t firstNonZero = result.find_first_not_of('0');
    if (firstNonZero == string::npos) {
        return "0";  // Если все нули
    }
    result = result.substr(firstNonZero); // Обрезаем строку

    // Если число отрицательное, добавляем знак минуса
    if (isNegative) {
        result = "-" + result;
    }

    // Возвращаем визуальное представление и результат
    return visualRepresentation + " = " + result;
}

//-----------------------------------------------------------------------------
// Определяем функцию extraTask1
//-----------------------------------------------------------------------------
void extraTask1() {
    cout << "Выполнено дополнительное задание 1." << endl;

    int num = 123456789;
    string strNum = intToStringPow10(num);
    cout << "Число " << num << " в строку: " << strNum << endl;
}
