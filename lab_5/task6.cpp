#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Максимальное количество строк и максимальная длина строки
const int MAX_STRINGS = 25;
const int MAX_LENGTH = 80;

//-----------------------------------------------------------------------------
// Функция для проверки корректности ввода целого числа
//-----------------------------------------------------------------------------
int getValidInt(const string& prompt, int minVal, int maxVal) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        // Проверка на корректность ввода (число)
        if (cin.fail()) {
            cout << "Ошибка: некорректный ввод. Пожалуйста, введите целое число." << endl;
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
            continue;
        }

        // Проверка на принадлежность к диапазону
        if (input < minVal || input > maxVal) {
            cout << "Ошибка: число должно быть в диапазоне от " << minVal << " до " << maxVal << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода после числа
            return input;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    }
}

//-----------------------------------------------------------------------------
// Функция для ввода строк с проверкой на максимальное количество и длину
//-----------------------------------------------------------------------------
vector<string> inputStrings() {
    vector<string> strings;
    string input;
    cout << "Введите строки (не более " << MAX_STRINGS << ", пустая строка для завершения):\n";

    while (strings.size() < MAX_STRINGS) {
        cout << "Строка " << strings.size() + 1 << ": ";
        getline(cin, input);

        if (input.empty()) {
            break; // Завершаем ввод, если введена пустая строка
        }

        if (input.length() > MAX_LENGTH) {
            cout << "Ошибка: строка слишком длинная (максимум " << MAX_LENGTH << " символов).\n";
        } else {
            strings.push_back(input);
        }
    }

    return strings;
}

//-----------------------------------------------------------------------------
// Функция для сравнения строк по длине
//-----------------------------------------------------------------------------
bool compareByLength(const string& a, const string& b) {
    return a.length() < b.length();
}

//-----------------------------------------------------------------------------
// Функция для вывода строк
//-----------------------------------------------------------------------------
void printStrings(const vector<string>& strings) {
    cout << "\nРезультат:\n";
    for (const string& str : strings) {
        cout << str << endl;
    }
}

//-----------------------------------------------------------------------------
// Функция task6 для обработки и сортировки строк
//-----------------------------------------------------------------------------
void task6() {
    vector<string> strings = inputStrings();

    if (strings.empty()) {
        cout << "Не было введено ни одной строки.\n";
        return;
    }

    cout << "\nВыберите способ сортировки:\n";
    cout << "1. По длине\n";
    cout << "2. По алфавиту\n";

    int choice = getValidInt("Ваш выбор (1 или 2): ", 1, 2);

    if (choice == 1) {
        sort(strings.begin(), strings.end(), compareByLength); // Сортировка по длине
    } else {
        sort(strings.begin(), strings.end()); // Сортировка по алфавиту
    }

    printStrings(strings);
}
