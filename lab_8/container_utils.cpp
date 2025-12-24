#include "container_utils.h"
#include <iostream>
#include <random>
#include <set>

//-----------------------------------------------------------------------------
// Реализация метода для генерации контейнера случайных чисел
//-----------------------------------------------------------------------------
std::vector<int> ContainerUtils::generateRandomContainer(int size) {
    // Используем Mersenne Twister для генерации псевдослучайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // Определяем диапазон случайных чисел (от -100 до 100, можно изменить)
    std::uniform_int_distribution<> distrib(-100, 100);

    std::vector<int> container(size);
    for (int i = 0; i < size; ++i) {
        container[i] = distrib(gen); // Генерируем случайное число и добавляем в контейнер
    }
    return container;
}

//-----------------------------------------------------------------------------
// Реализация метода для вывода контейнера в консоль
//-----------------------------------------------------------------------------
void ContainerUtils::printContainer(const std::vector<int>& container) const {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl; // Перенос строки после каждых 10 элементов
        }
    }
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// Реализация метода для вывода контейнера в обратном порядке
//-----------------------------------------------------------------------------
void ContainerUtils::printReverseContainer(const std::vector<int>& container) const {
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
// Реализация метода для подсчета уникальных чисел в контейнере
//-----------------------------------------------------------------------------
int ContainerUtils::countUniqueNumbers(const std::vector<int>& container) const {
    // Используем std::set для хранения уникальных чисел
    std::set<int> uniqueNumbers(container.begin(), container.end());
    return uniqueNumbers.size();
}
