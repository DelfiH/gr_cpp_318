#ifndef CONTAINER_UTILS_H
#define CONTAINER_UTILS_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>

class ContainerUtils {
public:
    ContainerUtils() = default;

    // Метод для генерации контейнера случайных чисел
    std::vector<int> generateRandomContainer(int size);

    // Метод для вывода контейнера в консоль
    void printContainer(const std::vector<int>& container) const;

    // Метод для вывода контейнера в обратном порядке
    void printReverseContainer(const std::vector<int>& container) const;

    // Метод для подсчета уникальных чисел в контейнере
    int countUniqueNumbers(const std::vector<int>& container) const;
};

#endif // CONTAINER_UTILS_H
