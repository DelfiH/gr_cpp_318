/*
 * Лабораторная работа №8
 * Тема: "Исследование в С++ стандартной библиотеки шаблонов (STL), перегрузка операторов"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */
#include <iostream>
#include <limits>
#include "task1.h"
#include "task2.h"
#include "task2_a.h"
#include "task2_b.h"
#include "task2_c.h"
#include "task3.h"
#include "tree.h"
#include "ring_buffer.h"

int main() {
    int choice;

    do {
        std::cout << "Меню заданий:\n";
        std::cout << "1. Задание 1.a\n";
        std::cout << "2. Задание 1.b\n";
        std::cout << "3. Задание A (Смешать вектор и список)\n";
        std::cout << "4. Задание B (Среднее арифметическое в списке)\n";
        std::cout << "5. Задание C (Топ-3 любимых вещей)\n";
        std::cout << "6. Задание 3 (Преобразование единиц информации)\n";
        std::cout << "7. Задание с деревом\n";
        std::cout << "8. Задание с кольцевым буфером\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите задание: ";

        std::cin >> choice;

        // Проверка на некорректный ввод
        if (std::cin.fail()) {
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    runTask1();
                    break;
                case 2:
                    runTask2();
                    break;
                case 3:
                    TaskA::run_task_a();  // Вызов задания A (Смешать вектор и список)
                    break;
                case 4:
                    TaskB::run_task_b();  // Вызов задания B (Среднее арифметическое в списке)
                    break;
                case 5:
                    TaskC::run_task_c();  // Вызов задания C (Топ-3 любимых вещей)
                    break;
                case 6:
                    Task3::run_task_3();  // Вызов задания 3 (Преобразование единиц информации)
                    break;
                case 7:
                    run_tree_task();  // Вызываем функцию для дерева
                    break;
                case 8:
                    run_ring_buffer_task();  // Вызываем функцию для кольцевого буфера
                    break;
                case 0:
                    std::cout << "Выход из программы.\n";
                    break;
                default:
                    std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите число.\n";
            }
        }
    } while (choice != 0);

    return 0;
}
