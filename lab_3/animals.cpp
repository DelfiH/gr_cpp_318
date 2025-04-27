#include "animals.h"

void getAnimalName(Animal animal) {
    switch (animal) {
        case Animal::PIG:
            std::cout << "������" << std::endl;
            break;
        case Animal::CHICKEN:
            std::cout << "����" << std::endl;
            break;
        case Animal::GOAT:
            std::cout << "����" << std::endl;
            break;
        case Animal::CAT:
            std::cout << "���" << std::endl;
            break;
        case Animal::DOG:
            std::cout << "������" << std::endl;
            break;
        default:
            std::cout << "�������⭮� ����⭮�" << std::endl;
    }
}

void printNumberOfLegs(Animal animal) {
    switch (animal) {
        case Animal::PIG:
            std::cout << "������⢮ ���: 4" << std::endl;
            break;
        case Animal::CHICKEN:
            std::cout << "������⢮ ���: 2" << std::endl;
            break;
        case Animal::GOAT:
            std::cout << "������⢮ ���: 4" << std::endl;
            break;
        case Animal::CAT:
            std::cout << "������⢮ ���: 4" << std::endl;
            break;
        case Animal::DOG:
            std::cout << "������⢮ ���: 4" << std::endl;
            break;
        default:
            std::cout << "�������⭮� ����⭮�" << std::endl;
    }
}
