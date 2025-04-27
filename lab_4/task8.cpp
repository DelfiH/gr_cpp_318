#include "tasks.h"
#include <iostream>
#include <functional>

// ����� 㪠��⥫� �� �㭪��
int andFuncPtr(int a, int b) { return a & b; }
int orFuncPtr(int a, int b) { return a | b; }
int xorFuncPtr(int a, int b) { return a ^ b; }

// �㭪�� � 㪠��⥫�� �� �㭪��
int calculateWithFunctionPtr(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// std::function
int calculateWithStdFunction(int a, int b, std::function<int(int, int)> operation) {
    return operation(a, b);
}

void task8() {
    int choice, a, b;
    std::cout << "�롥�� �������� �㭪�� (1-�, 2-���, 3-XOR): ";
    std::cin >> choice;

    if (choice < 1 || choice > 3) {
        std::cerr << "�訡��: ������ �롮� �㭪樨.\n";
        return;
    }

    std::cout << "������ ��� 楫�� �᫠: ";
    std::cin >> a >> b;

    int result;

#ifdef USE_STD_FUNCTION
    std::function<int(int, int)> func;
    switch (choice) {
        case 1: func = andFuncPtr; break;
        case 2: func = orFuncPtr; break;
        case 3: func = xorFuncPtr; break;
    }
    result = calculateWithStdFunction(a, b, func);
    std::cout << "������� (std::function): " << result << std::endl;
#else
    int (*funcPtr)(int, int) = nullptr;
    switch (choice) {
        case 1: funcPtr = andFuncPtr; break;
        case 2: funcPtr = orFuncPtr; break;
        case 3: funcPtr = xorFuncPtr; break;
    }
    result = calculateWithFunctionPtr(a, b, funcPtr);
    std::cout << "������� (㪠��⥫� �� �㭪��): " << result << std::endl;
#endif
}
