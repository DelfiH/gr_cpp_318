/*
* Лабораторная работа № 3.1
* Тема: "Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator"
* Разработчик: Васин Сергей
* OS: Windows
* Группа: gr_cpp318
* Кодировка: ibm866
*/
#include <QApplication>
#include <iostream>
#include "probabilities.h"
#include "initialization.h"
#include "animals.h"
#include "min_max.h"
#include "type_cast.h"
#include "elevator.h"
#include "printChar.h"
#include "animal_menu.h"

using namespace std;

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
    showAnimalMenu(); // Вызов функции для отображения и обработки выбора животного
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


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int choice;

    while (true) {
        // Основное меню
        std::cout << "\nВыберите задание (1-7) или 0 для выхода: " << std::endl;
        std::cout << "1. Вычисление вероятности" << std::endl;
        std::cout << "2. Приведение вариантов вызова" << std::endl;
        std::cout << "3. демонстрации различных типов инициализации" << std::endl;
        std::cout << "4. Выбор животного" << std::endl;
        std::cout << "5. Найти большее/меньшее" << std::endl;
        std::cout << "6. Преобразование типов данных" << std::endl;
        std::cout << "7. Виртуальный лифт" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cin >> choice;

        if ((choice >= 1 && choice <= 7) || choice == 0) {
            switch (choice) {
                case 1: task1(); break;
                case 2: task2(); break;
                case 3: task3(); break;
                case 4: task4(); break;
                case 5: task5(); break;
                case 6: task6(); break;
                case 7: task7(); break;
                case 0:
                    std::cout << "Выход из программы." << std::endl;
                    return 0; // Просто выходим из функции main
            }
        } else {
            std::cout << "Неверный выбор задания. Пожалуйста, попробуйте снова." << std::endl;
        }
    }
    return app.exec(); // Запускаем цикл обработки событий Qt в конце main()
}
