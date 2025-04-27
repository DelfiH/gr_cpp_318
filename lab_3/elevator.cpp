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

// �㭪�� ��� �ਢ������ ��ப� � ������� ॣ�����
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void virtual_elevator() {
    int chosen_level;
    std::string exit_choice;

    std::cout << "\n���� ���������� � ����㠫�� ����!" << std::endl;
    std::cout << "\n�⠦�:" << std::endl;
    std::cout << "0 - ��મ���" << std::endl;
    std::cout << "1 - ����⥠��" << std::endl;
    std::cout << "2 - �㤪���" << std::endl;
    std::cout << "3 - ��஢�� ����" << std::endl;
    std::cout << "4 - ��������" << std::endl;
    std::cout << "5 - ����⧠�" << std::endl;
    std::cout << "6 - ������⥪�" << std::endl;
    std::cout << "7 - ����" << std::endl;

    while (true) {
        std::cout << "\n��������, �롥�� �⠦ (0-7): ";
        std::cin >> chosen_level;

        if (chosen_level < 0 || chosen_level > 7) {
            std::cout << "������ �⠦. ���஡�� ᭮��." << std::endl;
            continue;
        }

        switch (chosen_level) {
            case PARKING: std::cout << "\n�� �� ��મ���." << std::endl; break;
            case CINEMA: std::cout << "\n�� � ����⥠��." << std::endl; break;
            case FOOD_COURT: std::cout << "\n�� �� �㤪���." << std::endl; break;
            case GAMES: std::cout << "\n�� � ��஢�� ����." << std::endl; break;
            case SHOPPING: std::cout << "\n�� � ���������." << std::endl; break;
            case GYM: std::cout << "\n�� � ᯮ�⧠��." << std::endl; break;
            case LIBRARY: std::cout << "\n�� � ������⥪�." << std::endl; break;
            case ROOFTOP: std::cout << "\n�� �� ����." << std::endl; break;
            default:
                std::cout << "\n��������� �⠦." << std::endl;
                break;
        }

        std::cout << "\n�� ��� �������� �࣮�� 業��? (��/���): ";
        std::cin >> exit_choice;

        // �ਢ���� �������� ⥪�� � ������� ॣ�����
        std::string lower_exit_choice = toLower(exit_choice);

        if (lower_exit_choice == "��") {
            std::cout << "\n�� ᢨ�����!" << std::endl;
            break;
        }
    }
}
