// animals.cpp
#include <iostream>
#include <limits>
#include "animals.h"

Animal getAnimalFromInput() {
    int choice;
    std::cout << "\nВыберите животное:" << std::endl;
    std::cout << "0 - Свинья" << std::endl;
    std::cout << "1 - Курица" << std::endl;
    std::cout << "2 - Коза" << std::endl;
    std::cout << "3 - Кот" << std::endl;
    std::cout << "4 - Собака" << std::endl;

    while (true) {
        std::cout << "Ваш выбор: ";
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка: Пожалуйста, введите число от 0 до 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice >= 0 && choice <= 4) {
            return static_cast<Animal>(choice);
        } else {
            std::cout << "Неверный выбор. Пожалуйста, выберите число от 0 до 4." << std::endl;
        }
    }
}

void getAnimalName(Animal animal) {
    switch (animal) {
        case Animal::PIG:
            std::cout << "Свинья" << std::endl;
            break;
        case Animal::CHICKEN:
            std::cout << "Курица" << std::endl;
            break;
        case Animal::GOAT:
            std::cout << "Коза" << std::endl;
            break;
        case Animal::CAT:
            std::cout << "Кот" << std::endl;
            break;
        case Animal::DOG:
            std::cout << "Собака" << std::endl;
            break;
        default:
            std::cout << "Неизвестное животное" << std::endl;
    }
}

void printNumberOfLegs(Animal animal) {
    switch (animal) {
        case Animal::PIG:
            std::cout << "Количество лап: 4" << std::endl;
            break;
        case Animal::CHICKEN:
            std::cout << "Количество лап: 2" << std::endl;
            break;
        case Animal::GOAT:
            std::cout << "Количество лап: 4" << std::endl;
            break;
        case Animal::CAT:
            std::cout << "Количество лап: 4" << std::endl;
            break;
        case Animal::DOG:
            std::cout << "Количество лап: 4" << std::endl;
            break;
        default:
            std::cout << "Неизвестное животное" << std::endl;
    }
}

void showAnimalMenu() {
    Animal chosenAnimal = getAnimalFromInput();
    getAnimalName(chosenAnimal);
    printNumberOfLegs(chosenAnimal);
}
