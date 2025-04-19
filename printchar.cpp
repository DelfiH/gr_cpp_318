#include <iostream>
#include "printChar.h"

using namespace std;

// ������� �㭪樨 � ��ࠬ��ࠬ� �� 㬮�砭��
void printChar(int a, char b, char c, char d) {
    cout << "��㬥��� �㭪樨: " << a << " " << b << " " << c << " " << d << endl;
}

// �맮� �㭪樨 printChar � ࠧ���묨 ��㬥�⠬�
void testPrintChar() {
    cout << "�맮� �㭪樨 printChar() ��� ��㬥�⮢:" << endl;
    printChar(); // �ᯮ���� ���祭�� �� 㬮�砭��

    cout << "\n�맮� �㭪樨 printChar() � ����� ��㬥�⮬:" << endl;
    printChar('x'); // a = 'x', b = 'b', c = 'c', d = 'd'

    cout << "\n�맮� �㭪樨 printChar() � ���� ��㬥�⠬�:" << endl;
    printChar('x', 'y'); // a = 'x', b = 'y', c = 'c', d = 'd'

    cout << "\n�맮� �㭪樨 printChar() � �६� ��㬥�⠬�:" << endl;
    printChar('x', 'y', 'z'); // a = 'x', b = 'y', c = 'z', d = 'd'

    cout << "\n�맮� �㭪樨 printChar() � ������ ��㬥�⠬�:" << endl;
    printChar('x', 'y', 'z', 'w'); // a = 'x', b = 'y', c = 'z', d = 'w'
}
