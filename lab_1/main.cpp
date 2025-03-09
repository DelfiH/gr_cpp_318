#include <iostream>
#include <iomanip> // Для форматирования вывода

int main() {
        std::cout << std::setw(65) << "Задание 1" << std::endl; // Вывод информации о себе
        std::cout << std::endl << "Номер группы: 318, факультет: Доп. Образование" << std::endl; //Вывод информации о  номере группы, факультета
        std::cout << "Разработчики программы:" << std::endl << "1. Васин Сергей" << std::endl; //Вывод фамилии и имени разработчика программы
        std::cout << "Номер Лабораторной работы: 1" << std::endl; //Вывод

        std::cout << std::endl << std::setw(65) << "Задание 2" << std::endl; // Вывод информации о себе
        std::cout << std::endl << "*****" << std::setw(58) << "ТУСУР" << std::setw(57)  << "*****" << std::endl;
        std::cout << std::endl << std::right << std::setw(117) << "Факультет: Доп.Образование" << std::endl;
        std::cout << std::setw(102) << "Группа: 318" << std::endl;
        std::cout << std::setw(112) << "Студент: Васин Сергей" << std::endl;
        std::cout << std::endl << std::setw(66) << "Томск 2025" << std::endl;

        std::cout << std::endl << std::setw(65) << "Задание 3" << std::endl; // Задачи на вычисление определенного значения

    double Distance, Time, Speed; // Переменные в Pascal case
        std::cout << std::endl << std::setw(80) << "Вычисление скорости прямолинейного движения." << std::endl; //  Вычисление скорости прямолинейного движения
        std::cout << std::endl << "Введите расстояние (м): "; // Ввод значения расстояния
        std::cin >> Distance; // Вывод результата дистанции
        std::cout << "Введите время (с): "; // Ввод значения времени
        std::cin >> Time; // Вывод результата времени
        Speed = Distance / Time; // Формула вычисления скорости прямолинейного движения
        std::cout << "Скорость прямолинейного движения: " << Speed << " м/с" << std::endl; // Вывод результата скорости прямолинейного движения

    double InitialSpeed, FinalSpeed, Acceleration; // Переменные в Pascal case
        std::cout << std::endl << std::setw(72)<< "Вычисление ускорения." << std::endl; // Вычисление ускорения
        std::cout << std::endl << "Введите начальную скорость (м/с): "; // Ввод начальной скорости
        std::cin >> InitialSpeed; // Вывод значения начальной скорости
        std::cout << "Введите конечную скорость (м/с): "; // Ввод конечной скорости
        std::cin >> FinalSpeed; // Вывод введенного значения конечной скорости
        std::cout << "Введите время (с): "; // Ввод времени
        std::cin >> Time; // Вывод введенного значения время
        Acceleration = (FinalSpeed - InitialSpeed) / Time; // Формула вычисления ускорения
        std::cout << "Ускорение: " << Acceleration << " м/с" << std::endl; // Вывод результата вычисления ускорения

    double Circumference, Radius; // Переменные в Pascal case
        std::cout << std::endl << std::setw(74) << "Вычисление радиуса круга." << std::endl; // Вычисление радиуса круга
        std::cout << std::endl << "Введите длину окружности (м): "; // Ввод длины окружности
        std::cin >> Circumference; // Вывод введенного значения длина окружности
        Radius = Circumference / (2 * 3.14); // Используем значение 3.14
        std::cout << "Радиус круга: " << Radius << " м" << std::endl; // Вывод результата радиуса круга
        std::cout << std::endl << "Нажмите клавишу Enter для закрытия программы" << std::endl; // Нажать на клавишу Enter дабы закрыть окно
    return 0; // Закрытие программы
}
    // Объем *.exe файла в режиме Release: 49 КБ
    // Объем *.exe файла в режиме Debug: 70 КБ



