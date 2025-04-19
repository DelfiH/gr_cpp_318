#include "animals.h"

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
