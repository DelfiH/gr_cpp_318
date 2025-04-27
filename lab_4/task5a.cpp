#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для заполнения массива случайными числами
template <typename T>
void fillRandom(vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = static_cast<T>(rand()) / static_cast<T>(RAND_MAX); // Генерация случайного числа от 0 до 1
    }
}

// Функция сортировки пузырьком
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция для вывода массива
template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int type, n;

    cout << "Выберите тип данных массива:" << endl;
    cout << "1 - char, 2 - short, 3 - int, 4 - float, 5 - double" << endl;
    cout << "Ваш выбор: ";
    cin >> type;

    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    srand(time(0)); // Инициализация генератора случайных чисел

    switch (type) {
        case 1: {
            vector<char> arr(n);
            fillRandom(arr);
            cout << "Исходный массив: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "Отсортированный массив: ";
            printArray(arr);
            break;
        }
        case 2: {
            vector<short> arr(n);
            fillRandom(arr);
            cout << "Исходный массив: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "Отсортированный массив: ";
            printArray(arr);
            break;
        }
        case 3: {
            vector<int> arr(n);
            fillRandom(arr);
            cout << "Исходный массив: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "Отсортированный массив: ";
            printArray(arr);
            break;
        }
        case 4: {
            vector<float> arr(n);
            fillRandom(arr);
            cout << "Исходный массив: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "Отсортированный массив: ";
            printArray(arr);
            break;
        }
        case 5: {
            vector<double> arr(n);
            fillRandom(arr);
            cout << "Исходный массив: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "Отсортированный массив: ";
            printArray(arr);
            break;
        }
        default:
            cout << "Неверный выбор типа данных." << endl;
            return 1;
    }

    return 0;
}
