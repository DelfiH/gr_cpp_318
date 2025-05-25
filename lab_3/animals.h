#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>

enum class Animal {
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG
};

void getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

#endif // ANIMALINFO_H
