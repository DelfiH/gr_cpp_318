/*
 * Лабораторная работа №9
 * Тема: "Исследование в С++ чтения/запись в файл, шаблоны в IDE Qt Creator"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */
#include <iostream>
#include <limits>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Analyzer.h"
#include "filevector.h"
#include "ascii_art.h" // Добавлена ссылка на ascii_art.h

// Объявления функций из других файлов
void processDatabase();
void fileVectorMenu();
void matrixMenu();
//void saveImagesToFile(int choice1, int choice2, const std::string& filename); // Предполагается, что она уже объявлена в ascii_art.h
// Определение функции для получения целого числа с проверкой
int getIntInput() {
    int input;
    std::cin >> input;
    while (std::cin.fail()) {
        std::cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    }
    return input;
}

// Функция для отображения меню
void displayMenu() {
    std::cout << "\n=== Меню выбора заданий ===" << std::endl;
    std::cout << "1.  FileVector" << std::endl;
    std::cout << "2.  Матрица" << std::endl;
    std::cout << "3.  Поиск по базе данных" << std::endl;
    std::cout << "4.  Анализатор" << std::endl;
    std::cout << "5.  Запись в файл на картинках" << std::endl;
    std::cout << "0.  Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

int main() {
    srand(time(0));
    int choice;

    while (true) {
        displayMenu(); // Вывод меню

        choice = getIntInput(); // Получение ввода пользователя с проверкой

        switch (choice) {
            case 1:
                fileVectorMenu();
                break;
            case 2:
                matrixMenu();
                break;
            case 3:
                processDatabase();
                break;
            case 4: { // Добавляем фигурные скобки для области видимости
                std::string filename;
                std::cout << "Введите имя файла для анализа: ";
                std::cin >> filename;
                runCodeAnalyzer(filename);
                break;
            }
            case 5: {
                std::string filename;
                int choice1, choice2;

                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> filename;

                std::cout << "Выберите номер первого изображения (1-3): ";
                std::cin >> choice1;

                std::cout << "Выберите номер второго изображения (1-3): ";
                std::cin >> choice2;

                saveImagesToFile(choice1, choice2, filename); // Вызываем функцию с параметрами
                break;
            }
            case 0:
                std::cout << "Выход из программы." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите задание из списка." << std::endl;
        }
    }

    return 0;
}
