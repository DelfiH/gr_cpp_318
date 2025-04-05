#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <iostream>
#include <limits>

using namespace std;

double safeInput() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) { // �஢�ઠ �� �訡�� �����
            cin.clear(); // ���� ���ﭨ� ��⮪�
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���⪠ ����
            cout << "�訡�� �����. ��������, ������ �᫮ � ������饩 �窮�: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���⪠ ���� ��᫥ �ᯥ譮�� �����
            return value; // ������ ���४⭮�� ���祭��
        }
    }
}


#endif // MY_FUNCTIONS_H
