#ifndef TASK5_H
#define TASK5_H

#include <iostream>

// Объявление дружественной функции (должно быть видно в обоих классах)
class Brick; // Forward declaration
class Hole3D; // Forward declaration

bool canBrickFit(const Brick& brick, const Hole3D& hole);

// Класс Brick
class Brick {
private:
    double height;
    double length;
    double width;

public:
    // Конструктор
    Brick(double h, double l, double w);

    // Геттеры
    double getHeight() const;
    double getLength() const;
    double getWidth() const;

    // Метод для получения размеров кирпича в отсортированном порядке
    void getSortedDimensions(double dimensions[3]) const;

    // Метод для отображения проекций кирпича
    void displayProjections() const;
};

// Класс Hole3D
class Hole3D {
private:
    double height;
    double length;
    double width;

public:
    // Конструктор
    Hole3D(double h, double l, double w);

    // Геттеры
    double getHeight() const;
    double getLength() const;
    double getWidth() const;

    // Метод для получения размеров отверстия в отсортированном порядке
    void getSortedDimensions(double dimensions[3]) const;

    // Метод для отображения проекций отверстия
    void displayProjections() const;
};

// Объявление функции task5 (чтобы main.cpp знал о ней)
void task5();

#endif
