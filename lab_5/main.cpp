/*
 * Лабораторная работа №5
 * Тема: "Исследование строк, структур памяти С++ в IDE Qt Creator"
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
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include "extratask1.h"
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
  cout << "1.  Вывод адресов памяти" << endl;
  cout << "2.  Новый вид" << endl;
  cout << "3.  Материки, страны, города" << endl;
  cout << "4.  Упаковка/Распаковка строк" << endl;
  cout << "5.  Обработка пробелов и табуляции" << endl;
  cout << "6.  Проверка строки на валидность" << endl;
  cout << "7.  Преобразование числа в строку и строки в число" << endl;
  cout << "8.  Обработка почтовых адресов" << endl;
  cout << "9.  Дополнительное задание 1 (Преобразование числа в строку с использованием степеней 10)" << endl;
  cout << "10. Дополнительное задание 2 (Эмулятор 'Запрос-Ответ')" << endl;
  cout << "0.  Выход" << endl;
  cout << "Ваш выбор: ";
}

int main() {
  int choice;

  while (true) {
    displayMenu(); // Вывод меню

    choice = getIntInput(); // Получение ввода пользователя с проверкой

    switch (choice) {
      case 1:
        task1(); // Вызов функции задания 1
        break;
      case 2:
        task2(); // Вызов функции задания 2
        break;
      case 3:
        task3(); // Вызов функции задания 3
        break;
      case 4:
        task4(); // Вызов функции задания 4
        break;
      case 5:
        task5(); // Вызов функции задания 5
        break;
      case 6:
        task6(); // Вызов функции задания 6
        break;
      case 7:
        task7(); // Вызов функции задания 7
        break;
      case 8:
        task8(); // Вызов функции задания 8
        break;
      case 9:
        extraTask1(); // Вызов функции дополнительного задания 1
        break;
      case 10:
        extraTask2(); // Вызов функции дополнительного задания 2
        break;
      case 0:
        cout << "Выход из программы." << endl;
        return 0;
      default:
        cout << "Неверный выбор. Пожалуйста, выберите задание из списка."
             << endl;
    }
  }

  return 0;
}
