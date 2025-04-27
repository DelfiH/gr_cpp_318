#include "tasks.h"
#include <iostream>

// Задание 6a: Указатели и адреса
void task6a() {
    int m;
    float fx;
    char cht;

    std::cout << "Указатель: продемонстрировать использование операторов & и *\n";
    std::cout << "------------------------------------------------------\n";

    std::cout << "Введите целое число m: ";
    std::cin >> m;
    std::cout << "Введите число с плавающей точкой fx: ";
    std::cin >> fx;
    std::cout << "Введите символ cht: ";
    std::cin >> cht;

    std::cout << "m = " << m << std::endl;
    std::cout << "fx = " << fx << std::endl;
    std::cout << "cht = " << cht << std::endl;

    std::cout << "\nИспользование & оператор:\n";
    std::cout << "----------------------\n";
    std::cout << "адрес m = " << &m << std::endl;
    std::cout << "адрес fx = " << &fx << std::endl;
    std::cout << "адрес cht = " << &cht << std::endl;

    std::cout << "\nИспользуя операторы & и *:\n";
    std::cout << "-----------------------------\n";
    std::cout << "значение по адресу m = " << *(&m) << std::endl;
    std::cout << "значение по адресу fx = " << *(&fx) << std::endl;
    std::cout << "значение по адресу cht = " << *(&cht) << std::endl;

    std::cout << "\nИспользуя только переменную указателя:\n";
    std::cout << "----------------------------------\n";
    int* ptr_m = &m;
    float* ptr_fx = &fx;
    char* ptr_cht = &cht;

    std::cout << "адрес m = " << ptr_m << std::endl;
    std::cout << "адрес fx = " << ptr_fx << std::endl;
    std::cout << "адрес cht = " << ptr_cht << std::endl;

    std::cout << "\nИспользование только оператора указателя:\n";
    std::cout << "----------------------------------\n";
    std::cout << "значение по адресу m = " << *ptr_m << std::endl;
    std::cout << "значение по адресу fx = " << *ptr_fx << std::endl;
    std::cout << "значение по адресу cht = " << *ptr_cht << std::endl;
}

// Задание 6b: Хранение и печать элементов массива с помощью указателя
void task6b() {
    int n;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Ошибка: размер массива должен быть положительным.\n";
        return;
    }

    int* arr = new int[n]; // Динамическое выделение памяти

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Элементы массива, напечатанные с помощью указателя:\n";
    int* ptr = arr; // Указатель на начало массива
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = " << *ptr << " (адрес: " << ptr << ")\n";
        ++ptr; // Перемещаем указатель на следующий элемент
    }

    delete[] arr; // Освобождение выделенной памяти
    arr = nullptr; // Устанавливаем указатель в nullptr, чтобы избежать "висячих" указателей
}
