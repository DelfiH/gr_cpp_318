#include <iostream>
#include <string>
#include <algorithm>
#include "elevator.h"

enum Level {
    PARKING = 0,
    CINEMA = 1,
    FOOD_COURT = 2,
    GAMES = 3,
    SHOPPING = 4,
    GYM = 5,
    LIBRARY = 6,
    ROOFTOP = 7,
};

// Функция для приведения строки к нижнему регистру
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void virtual_elevator() {
    int chosen_level;
    std::string exit_choice;

    std::cout << "\nДобро пожаловать в виртуальный лифт!" << std::endl;
    std::cout << "\nЭтажи:" << std::endl;
    std::cout << "0 - Парковка" << std::endl;
    std::cout << "1 - Кинотеатр" << std::endl;
    std::cout << "2 - Фудкорт" << std::endl;
    std::cout << "3 - Игровая зона" << std::endl;
    std::cout << "4 - Магазины" << std::endl;
    std::cout << "5 - Спортзал" << std::endl;
    std::cout << "6 - Библиотека" << std::endl;
    std::cout << "7 - Крыша" << std::endl;

    while (true) {
        std::cout << "\nПожалуйста, выберите этаж (0-7): ";
        std::cin >> chosen_level;

        if (chosen_level < 0 || chosen_level > 7) {
            std::cout << "Неверный этаж. Попробуйте снова." << std::endl;
            continue;
        }

        switch (chosen_level) {
            case PARKING: std::cout << "\nВы на парковке." << std::endl; break;
            case CINEMA: std::cout << "\nВы в кинотеатре." << std::endl; break;
            case FOOD_COURT: std::cout << "\nВы на фудкорте." << std::endl; break;
            case GAMES: std::cout << "\nВы в игровой зоне." << std::endl; break;
            case SHOPPING: std::cout << "\nВы в магазинах." << std::endl; break;
            case GYM: std::cout << "\nВы в спортзале." << std::endl; break;
            case LIBRARY: std::cout << "\nВы в библиотеке." << std::endl; break;
            case ROOFTOP: std::cout << "\nВы на крыше." << std::endl; break;
            default:
                std::cout << "\nНеизвестный этаж." << std::endl;
                break;
        }

        std::cout << "\nВы хотите покинуть торговый центр? (да/нет): ";
        std::cin >> exit_choice;

        // Приводим введенный текст к нижнему регистру
        std::string lower_exit_choice = toLower(exit_choice);

        if (lower_exit_choice == "да") {
            std::cout << "\nДо свидания!" << std::endl;
            break;
        }
    }
}
