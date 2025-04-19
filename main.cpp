/*
 * ������ୠ� ࠡ�� �3.1
 * ����: ?��᫥������� �㭪権 �++ � IDE (��⥣�஢����� �।� ࠧࠡ�⪨) Qt Creator?
 * ���ࠡ��稪: ��ᨭ ��ࣥ�
 * ��㯯�: gr_cpp318
 * OS: Windows
 * locale (����஢��): ibm866
 */

#include "probabilities.h"
#include "initialization.h"
#include "animals.h"
#include "min_max.h"
#include "type_cast.h"
#include "elevator.h"
#include <QApplication>
#include <QWidget>
#include <iostream>
#include "calculator.h"
#include "printChar.h"
#include "animal_menu.h"

using namespace std;

void getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

// �㭪�� ��� ������� 1
void task1() {
    std::cout << "������� 1" << std::endl;
    calculate_probabilities();
}

// �㭪�� ��� ������� 2
void task2() {
    std::cout << "������� 2" << std::endl;
    testPrintChar();
}

// �㭪�� ��� ������� 3
void task3() {
    std::cout << "������� 3" << std::endl;
    demonstrate_initialization();
}

// �㭪�� ��� ������� 4
void task4() {
    std::cout << "������� 4" << std::endl;

}

// �㭪�� ��� ������� 5
void task5() {
    std::cout << "������� 5" << std::endl;
    find_min_max();
}

// �㭪�� ��� ������� 6
void task6() {
    std::cout << "������� 6" << std::endl;
    demonstrate_type_cast();
}

// �㭪�� ��� ������� 7
void task7() {
    std::cout << "������� 7" << std::endl;
    virtual_elevator();
}

// �㭪�� ��� ������� 8
void task8() {
    std::cout << "����� ��������" << std::endl;
    try {
        Calculator calc;
        calc.show();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred!" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int choice;

    while (true) {
        // �᭮���� ����
        std::cout << "\n�롥�� ������� (1-8) ��� 0 ��� ��室�: " << std::endl;
        std::cout << "1. ���᫥��� ����⭮��" << std::endl;
        std::cout << "2. �ਢ������ ��ਠ�⮢ �맮��" << std::endl;
        std::cout << "3. ��������樨 ࠧ����� ⨯�� ���樠����樨" << std::endl;
        std::cout << "4. �롮� ����⭮��" << std::endl;
        std::cout << "5. ���� ����襥/����襥" << std::endl;
        std::cout << "6. demonstrate_type_cast" << std::endl;
        std::cout << "7. ����㠫�� ����" << std::endl;
        std::cout << "8. ��������" << std::endl;
        std::cout << "0. ��室 �� �ணࠬ��" << std::endl;
        std::cin >> choice;

        if ((choice >= 1 && choice <= 8 && choice != 4) || choice == 0) {
            switch (choice) {
                case 1: task1(); break;
                case 2: task2(); break;
                case 3: task3(); break;
                case 5: task5(); break;
                case 6: task6(); break;
                case 7: task7(); break;
                case 8: task8(); break;
                case 0:
                    std::cout << "��室 �� �ணࠬ��." << std::endl;
                    return app.exec(); // �����蠥� 横� ��ࠡ�⪨ ᮡ�⨩ � ��室�� �� �ணࠬ��
            }
        } else if (choice == 4) {
            showAnimalMenu(); // �맮� �㭪樨 ��� �⮡ࠦ���� � ��ࠡ�⪨ �롮� ����⭮��
        } else {
            std::cout << "������ �롮� �������. ��������, ���஡�� ᭮��." << std::endl;
        }
    }

    return app.exec(); // ����᪠�� 横� ��ࠡ�⪨ ᮡ�⨩ Qt � ���� main()
}
