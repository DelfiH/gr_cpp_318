/*
 * Лабораторная работа №4
 * Тема: ?Исследование массивов, указателей, ссылок.?
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */
#include "tasks.h"
#include <iostream>

int main() {
    int choice;

    while (true) {
        std::cout << "Выберите задание для выполнения:\n";
        std::cout << "1. Задание 1\n";
        std::cout << "2. Задание 2\n";
        std::cout << "3. Задание 3\n";
        std::cout << "41. Задание 4 (подзадача A)\n";
        std::cout << "42. Задание 4 (подзадача B)\n";
        std::cout << "43. Задание 4 (подзадача C)\n";
        std::cout << "5. Задание 5\n";
        std::cout << "61. Задание 6 (подзадача A)\n";
        std::cout << "62. Задание 6 (подзадача B)\n";
        std::cout << "7. Задание 7\n";
        std::cout << "8. Задание 8\n";
        std::cout << "9. Задание 9\n";
        std::cout << "0. Выход\n";
        std::cout << "\nВаш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 41:  // Для подзадачи A задания 4
                task4a();
                break;
            case 42:  // Для подзадачи B задания 4
                task4b();
                break;
            case 43:  // Для подзадачи C задания 4
                task4c();
                break;
            case 5:
                task5();
                break;
            case 61:  // Для подзадачи A задания 6
                task6a();
                break;
            case 62:  // Для подзадачи B задания 6
                task6b();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            case 9:
                task9();
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    }

    return 0;
}
