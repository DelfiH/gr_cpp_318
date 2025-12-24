#include "task4.h"
#include <iostream>
#include <cmath> // Для математических функций
#include <limits> // Для numeric_limits

// Функция для проверки ввода на корректность (число с плавающей точкой)
double getDoubleInput(const std::string& prompt) {
    double input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cout << "Ошибка ввода. Пожалуйста, введите число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
            return input;
        }
    }
}

// Функция для сложения комплексных чисел
void addComplex(double real1, double imag1, double real2, double imag2, double& resultReal, double& resultImag) {
    resultReal = real1 + real2;
    resultImag = imag1 + imag2;
}

// Функция для вычитания комплексных чисел
void subtractComplex(double real1, double imag1, double real2, double imag2, double& resultReal, double& resultImag) {
    resultReal = real1 - real2;
    resultImag = imag1 - imag2;
}

// Функция для умножения комплексных чисел
void multiplyComplex(double real1, double imag1, double real2, double imag2, double& resultReal, double& resultImag) {
    resultReal = (real1 * real2) - (imag1 * imag2);
    resultImag = (real1 * imag2) + (imag1 * real2);
}

// Функция для деления комплексных чисел
void divideComplex(double real1, double imag1, double real2, double imag2, double& resultReal, double& resultImag) {
    double denominator = (real2 * real2) + (imag2 * imag2);
    resultReal = ((real1 * real2) + (imag1 * imag2)) / denominator;
    resultImag = ((imag1 * real2) - (real1 * imag2)) / denominator;
}

// Функция для вычисления сопряженного комплексного числа
void conjugateComplex(double real, double imag, double& resultReal, double& resultImag) {
    resultReal = real;
    resultImag = -imag;
}

// Функция для возведения комплексного числа в степень (только для целых степеней)
void powerComplex(double real, double imag, int power, double& resultReal, double& resultImag) {
    if (power == 0) {
        resultReal = 1.0;
        resultImag = 0.0;
        return;
    }

    resultReal = real;
    resultImag = imag;
    double tempReal, tempImag;

    for (int i = 1; i < power; ++i) {
        tempReal = (resultReal * real) - (resultImag * imag);
        tempImag = (resultReal * imag) + (resultImag * real);
        resultReal = tempReal;
        resultImag = tempImag;
    }
}

// Функция для извлечения квадратного корня из комплексного числа
void sqrtComplex(double real, double imag, double& resultReal1, double& resultImag1, double& resultReal2, double& resultImag2) {
    double magnitude = sqrt(real * real + imag * imag);
    resultReal1 = sqrt((magnitude + real) / 2);
    resultImag1 = (imag >= 0) ? sqrt((magnitude - real) / 2) : -sqrt((magnitude - real) / 2);
    resultReal2 = -resultReal1;
    resultImag2 = -resultImag1;
}

// Функция для преобразования в тригонометрическую форму
void toTrigonometricForm(double real, double imag, double& r, double& theta) {
    r = sqrt(real * real + imag * imag);
    theta = atan2(imag, real); // возвращает угол в радианах
}

// Функция для преобразования в экспоненциальную форму
void toExponentialForm(double real, double imag, double& r, double& theta) {
    toTrigonometricForm(real, imag, r, theta);
}

// Функция для вывода комплексного числа
void displayComplex(double real, double imag) {
    std::cout << real;
    if (imag >= 0) {
        std::cout << " + " << imag << "i";
    } else {
        std::cout << " - " << -imag << "i";
    }
}

// Функция для вывода комплексного числа в тригонометрической форме
void displayTrigonometricForm(double r, double theta) {
    std::cout << r << " * (cos(" << theta << ") + i * sin(" << theta << "))";
}

// Функция для вывода комплексного числа в экспоненциальной форме
void displayExponentialForm(double r, double theta) {
    std::cout << r << " * e^(i * " << theta << ")";
}

void Task4::run() {
    // Получаем ввод от пользователя для первого комплексного числа
    double real1 = getDoubleInput("Введите действительную часть первого комплексного числа: ");
    double imag1 = getDoubleInput("Введите мнимую часть первого комплексного числа: ");

    // Получаем ввод от пользователя для второго комплексного числа
    double real2 = getDoubleInput("Введите действительную часть второго комплексного числа: ");
    double imag2 = getDoubleInput("Введите мнимую часть второго комплексного числа: ");

    std::cout << "z1 = ";
    displayComplex(real1, imag1);
    std::cout << std::endl;

    std::cout << "z2 = ";
    displayComplex(real2, imag2);
    std::cout << std::endl;

    // Сложение
    double sumReal, sumImag;
    addComplex(real1, imag1, real2, imag2, sumReal, sumImag);
    std::cout << "z1 + z2 = ";
    displayComplex(sumReal, sumImag);
    std::cout << std::endl;

    // Вычитание
    double diffReal, diffImag;
    subtractComplex(real1, imag1, real2, imag2, diffReal, diffImag);
    std::cout << "z1 - z2 = ";
    displayComplex(diffReal, diffImag);
    std::cout << std::endl;

    // Умножение
    double prodReal, prodImag;
    multiplyComplex(real1, imag1, real2, imag2, prodReal, prodImag);
    std::cout << "z1 * z2 = ";
    displayComplex(prodReal, prodImag);
    std::cout << std::endl;

    // Деление
    double quotReal, quotImag;
    divideComplex(real1, imag1, real2, imag2, quotReal, quotImag);
    std::cout << "z1 / z2 = ";
    displayComplex(quotReal, quotImag);
    std::cout << std::endl;

    // Сопряжение
    double conjReal, conjImag;
    conjugateComplex(real1, imag1, conjReal, conjImag);
    std::cout << "Сопряженное z1 = ";
    displayComplex(conjReal, conjImag);
    std::cout << std::endl;

    // Возведение в степень
    int power = 2;
    double powReal, powImag;
    powerComplex(real1, imag1, power, powReal, powImag);
    std::cout << "z1 в степени " << power << " = ";
    displayComplex(powReal, powImag);
    std::cout << std::endl;

    // Извлечение квадратного корня
    double sqrtReal1, sqrtImag1, sqrtReal2, sqrtImag2;
    sqrtComplex(real1, imag1, sqrtReal1, sqrtImag1, sqrtReal2, sqrtImag2);
    std::cout << "Квадратные корни из z1: ";
    displayComplex(sqrtReal1, sqrtImag1);
    std::cout << " и ";
    displayComplex(sqrtReal2, sqrtImag2);
    std::cout << std::endl;

    // Преобразование в тригонометрическую форму
    double r, theta;
    toTrigonometricForm(real1, imag1, r, theta);
    std::cout << "z1 в тригонометрической форме: ";
    displayTrigonometricForm(r, theta);
    std::cout << std::endl;

    // Преобразование в экспоненциальную форму
    double r_exp, theta_exp;
    toExponentialForm(real1, imag1, r_exp, theta_exp);
    std::cout << "z1 в экспоненциальной форме: ";
    displayExponentialForm(r_exp, theta_exp);
    std::cout << std::endl;
}
