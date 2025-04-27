/*
 * ������ୠ� ࠡ�� �4
 * ����: ?��᫥������� ���ᨢ��, 㪠��⥫��, ��뫮�.?
 * ���ࠡ��稪: ��ᨭ ��ࣥ�
 * ��㯯�: gr_cpp318
 * OS: Windows
 * locale (����஢��): ibm866
 */
#include "tasks.h"
#include <iostream>

int main() {
    int choice;

    while (true) {
        std::cout << "�롥�� ������� ��� �믮������:\n";
        std::cout << "1. ������� 1\n";
        std::cout << "2. ������� 2\n";
        std::cout << "3. ������� 3\n";
        std::cout << "41. ������� 4 (�������� A)\n";
        std::cout << "42. ������� 4 (�������� B)\n";
        std::cout << "43. ������� 4 (�������� C)\n";
        std::cout << "5. ������� 5\n";
        std::cout << "61. ������� 6 (�������� A)\n";
        std::cout << "62. ������� 6 (�������� B)\n";
        std::cout << "7. ������� 7\n";
        std::cout << "8. ������� 8\n";
        std::cout << "9. ������� 9\n";
        std::cout << "0. ��室\n";
        std::cout << "\n��� �롮�: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 41:  // ��� �������� A ������� 4
                task4a();
                break;
            case 42:  // ��� �������� B ������� 4
                task4b();
                break;
            case 43:  // ��� �������� C ������� 4
                task4c();
                break;
            case 5:
                task5();
                break;
            case 61:  // ��� �������� A ������� 6
                task6a();
                break;
            case 62:  // ��� �������� B ������� 6
                task6b();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            case 9:
                task9();
                break;
            case 0:
                std::cout << "��室 �� �ணࠬ��.\n";
                return 0;
            default:
                std::cout << "������ �롮�. ���஡�� �� ࠧ.\n";
        }
    }

    return 0;
}
