#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <iostream>
#include <limits>

using namespace std;

double safeInput() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) { // Проверка на ошибку ввода
            cin.clear(); // Сброс состояния потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Ошибка ввода. Пожалуйста, введите число с плавающей точкой: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера после успешного ввода
            return value; // Возврат корректного значения
        }
    }
}


#endif // MY_FUNCTIONS_H
