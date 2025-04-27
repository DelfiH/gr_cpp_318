#include "animal_menu.h"

void getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

void showAnimalMenu() {
    int choice;
    std::cout << "\n�롥�� ����⭮�: \n1. ������\n2. ����\n3. ����\n4. ���\n5. ������\n";
    std::cout << "\n������ ����� ����⭮�� (1-5): ";
    std::cin >> choice;

    Animal selectedAnimal;

    switch (choice) {
        case 1: selectedAnimal = Animal::PIG; break;
        case 2: selectedAnimal = Animal::CHICKEN; break;
        case 3: selectedAnimal = Animal::GOAT; break;
        case 4: selectedAnimal = Animal::CAT; break;
        case 5: selectedAnimal = Animal::DOG; break;
        default: std::cout << "�������⭮� ����⭮�" << std::endl; return;
    }

    getAnimalName(selectedAnimal);
    printNumberOfLegs(selectedAnimal);
}
