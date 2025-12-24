#include "task2.h"
#include <iostream>
#include <limits>   // Для numeric_limits
#include "container_utils.h"

//-----------------------------------------------------------------------------
// Функция для выполнения задания 2
//-----------------------------------------------------------------------------
void runTask2() {
    int N;
    ContainerUtils utils;

    while (true) {
        std::cout << "Введите количество элементов N (от 1 до 1000): ";
        std::cin >> N;

        // Проверяем на некорректный ввод
        if (std::cin.fail()) {
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();  // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем некорректный ввод из потока
            continue;  // Переходим к следующей итерации цикла
        }

        // Проверяем, что N находится в допустимых пределах
        if (N < 1 || N > 1000) {
            std::cout << "Ошибка: N должно быть от 1 до 1000." << std::endl;
            continue;  // Переходим к следующей итерации цикла
        }

        // Если ввод корректный, выходим из цикла
        break;
    }

    std::vector<int> container = utils.generateRandomContainer(N);

    std::cout << "Содержимое контейнера в прямом порядке:" << std::endl;
    utils.printContainer(container);

    std::cout << "Содержимое контейнера в обратном порядке:" << std::endl;
    utils.printReverseContainer(container);
}
