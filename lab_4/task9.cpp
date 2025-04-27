#include "tasks.h"
#include <iostream>

void swapEvenOdd(int* arr) {
    for (int i = 0; i < 11; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void task9() {
    int myArray[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << "Исходный массив: ";
    for (int i = 0; i < 12; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    swapEvenOdd(myArray);

    std::cout << "Измененный массив: ";
    for (int i = 0; i < 12; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
}
