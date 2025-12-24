/*
 * Лабораторная работа №6
 * Тема: "Исследование С++ классов в IDE Qt Creator"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */
#include <iostream>
#include <limits>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "extratask2.h"

using namespace std;

// Функция для проверки ввода на корректность (целое число)
int getIntInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            return input;
        }
    }
}

// Функция для отображения меню
void displayMenu() {
    cout << "\n=== Меню выбора заданий ===" << endl;
    cout << "1.  Взлом пароля (Bruteforce)" << endl;
    cout << "2.  Проверка палиндрома" << endl;
    cout << "3.  Автобаза" << endl;
    cout << "4.  Комплексные числа" << endl;
    cout << "5.  Проверка размеров кирпича" << endl;
    cout << "6.  Игра 'Крестики-нолики'" << endl;
    cout << "0.  Выход" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    int choice;

    while (true) {
        displayMenu(); // Вывод меню

        choice = getIntInput(); // Получение ввода пользователя с проверкой

        switch (choice) {
            case 1: {
                // Код для задачи Bruteforce
                Bruteforce bruteforce;
                bruteforce.run();
                break;
            }
            case 2:
                task2(); // Вызов функции задания 2
                break;
            case 3: {
                Task3 task3; // Создаем объект Task3
                task3.run(); // Вызов метода run() через объект
                break;
            }
            case 4: {
                Task4 task4; // Создаем объект Task4
                task4.run(); // Вызов метода run() через объект
                break;
            }
            case 5:
                task5(); // Вызов функции задания 5
                break;
            case 6: {
                // Код для ExtraTask2 (TicTacToe)
                TicTacToe game;
                CellState currentPlayer = CellState::Cross; // Начинает крестик

                while (game.getGameState() == GameState::InProgress) {
                    game.printBoard(); // Выводим текущее состояние поля

                    cout << (currentPlayer == CellState::Cross ? "Ход крестиков (X)" : "Ход ноликов (O)") << endl;

                    if (game.playerMove(currentPlayer)) {
                        // Если ход удался, меняем игрока
                        currentPlayer = (currentPlayer == CellState::Cross ? CellState::Nought : CellState::Cross);
                    } else {
                        // Если ход не удался, даем игроку еще одну попытку
                        cout << "Попробуйте еще раз." << endl;
                    }
                }

                // После завершения игры
                game.printBoard();
                GameState gameState = game.getGameState();
                if (gameState == GameState::CrossWins) {
                    cout << "Крестики выиграли!" << endl;
                } else if (gameState == GameState::NoughtWins) {
                    cout << "Нолики выиграли!" << endl;
                } else {
                    cout << "Ничья!" << endl;
                }
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Неверный выбор. Пожалуйста, выберите задание из списка." << endl;
        }
    }

    return 0;
}
