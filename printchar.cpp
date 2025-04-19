#include <iostream>
#include "printChar.h"

using namespace std;

// Объявление функции с параметрами по умолчанию
void printChar(int a, char b, char c, char d) {
    cout << "Аргументы функции: " << a << " " << b << " " << c << " " << d << endl;
}

// Вызов функции printChar с различными аргументами
void testPrintChar() {
    cout << "Вызов функции printChar() без аргументов:" << endl;
    printChar(); // Использует значения по умолчанию

    cout << "\nВызов функции printChar() с одним аргументом:" << endl;
    printChar('x'); // a = 'x', b = 'b', c = 'c', d = 'd'

    cout << "\nВызов функции printChar() с двумя аргументами:" << endl;
    printChar('x', 'y'); // a = 'x', b = 'y', c = 'c', d = 'd'

    cout << "\nВызов функции printChar() с тремя аргументами:" << endl;
    printChar('x', 'y', 'z'); // a = 'x', b = 'y', c = 'z', d = 'd'

    cout << "\nВызов функции printChar() с четырьмя аргументами:" << endl;
    printChar('x', 'y', 'z', 'w'); // a = 'x', b = 'y', c = 'z', d = 'w'
}
