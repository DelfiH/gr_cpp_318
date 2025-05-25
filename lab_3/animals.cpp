// animals.cpp
#include <iostream>
#include <limits>
#include "animals.h"

Animal getAnimalFromInput() {
    int choice;
    std::cout << "\n�롥�� ����⭮�:" << std::endl;
    std::cout << "0 - ������" << std::endl;
    std::cout << "1 - ����" << std::endl;
    std::cout << "2 - ����" << std::endl;
    std::cout << "3 - ���" << std::endl;
    std::cout << "4 - ������" << std::endl;

    while (true) {
        std::cout << "��� �롮�: ";
        if (!(std::cin >> choice)) {
            std::cout << "�訡��: ��������, ������ �᫮ �� 0 �� 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice >= 0 && choice <= 4) {
            return static_cast<Animal>(choice);
        } else {
            std::cout << "������ �롮�. ��������, �롥�� �᫮ �� 0 �� 4." << std::endl;
        }
    }
}

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

void showAnimalMenu() {
    Animal chosenAnimal = getAnimalFromInput();
    getAnimalName(chosenAnimal);
    printNumberOfLegs(chosenAnimal);
}
