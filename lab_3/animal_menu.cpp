#include "animal_menu.h"

void getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

void showAnimalMenu() {
    int choice;
    std::cout << "\nВыберите животное: \n1. Свинья\n2. Курица\n3. Коза\n4. Кот\n5. Собака\n";
    std::cout << "\nВведите номер животного (1-5): ";
    std::cin >> choice;

    Animal selectedAnimal;

    switch (choice) {
        case 1: selectedAnimal = Animal::PIG; break;
        case 2: selectedAnimal = Animal::CHICKEN; break;
        case 3: selectedAnimal = Animal::GOAT; break;
        case 4: selectedAnimal = Animal::CAT; break;
        case 5: selectedAnimal = Animal::DOG; break;
        default: std::cout << "Неизвестное животное" << std::endl; return;
    }

    getAnimalName(selectedAnimal);
    printNumberOfLegs(selectedAnimal);
}
