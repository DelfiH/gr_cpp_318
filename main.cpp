/*
 * Лабораторная работа №3.1
 * Тема: ?Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator?
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */

#include "probabilities.h"
#include "initialization.h"
#include "animals.h"
#include "min_max.h"
#include "type_cast.h"
#include "elevator.h"
#include <QApplication>
#include <QWidget>
#include <iostream>
#include "calculator.h"
#include "printChar.h"
#include "animal_menu.h"

using namespace std;

void getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

// Функция для задания 1
void task1() {
    std::cout << "Задание 1" << std::endl;
    calculate_probabilities();
}

// Функция для задания 2
void task2() {
    std::cout << "Задание 2" << std::endl;
    testPrintChar();
}

// Функция для задания 3
void task3() {
    std::cout << "Задание 3" << std::endl;
    demonstrate_initialization();
}

// Функция для задания 4
void task4() {
    std::cout << "Задание 4" << std::endl;

}

// Функция для задания 5
void task5() {
    std::cout << "Задание 5" << std::endl;
    find_min_max();
}

// Функция для задания 6
void task6() {
    std::cout << "Задание 6" << std::endl;
    demonstrate_type_cast();
}

// Функция для задания 7
void task7() {
    std::cout << "Задание 7" << std::endl;
    virtual_elevator();
}

// Функция для задания 8
void task8() {
    std::cout << "Запуск калькулятора" << std::endl;
    try {
        Calculator calc;
        calc.show();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred!" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int choice;

    while (true) {
        // Основное меню
        std::cout << "\nВыберите задание (1-8) или 0 для выхода: " << std::endl;
        std::cout << "1. Вычисление вероятности" << std::endl;
        std::cout << "2. Приведение вариантов вызова" << std::endl;
        std::cout << "3. демонстрации различных типов инициализации" << std::endl;
        std::cout << "4. Выбор животного" << std::endl;
        std::cout << "5. найти большее/меньшее" << std::endl;
        std::cout << "6. demonstrate_type_cast" << std::endl;
        std::cout << "7. виртуальный лифт" << std::endl;
        std::cout << "8. Калькулятор" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cin >> choice;

        if ((choice >= 1 && choice <= 8 && choice != 4) || choice == 0) {
            switch (choice) {
                case 1: task1(); break;
                case 2: task2(); break;
                case 3: task3(); break;
                case 5: task5(); break;
                case 6: task6(); break;
                case 7: task7(); break;
                case 8: task8(); break;
                case 0:
                    std::cout << "Выход из программы." << std::endl;
                    return app.exec(); // Завершаем цикл обработки событий и выходим из программы
            }
        } else if (choice == 4) {
            showAnimalMenu(); // Вызов функции для отображения и обработки выбора животного
        } else {
            std::cout << "Неверный выбор задания. Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return app.exec(); // Запускаем цикл обработки событий Qt в конце main()
}
