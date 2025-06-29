#include "tasks.h"
#include <iostream>
#include <functional>
#include <limits>
#include <string>
#include <sstream>
#include <map>
#include "safeinput.h"

// Type aliases ��� ���襭�� �⠥����
using int_operation = std::function<int(int, int)>;
using func_ptr = int (*)(int, int);

// ����� �㭪樨
int andFuncPtr(int a, int b) { return a & b; }
int orFuncPtr(int a, int b) { return a | b; }
int xorFuncPtr(int a, int b) { return a ^ b; }

// �㭪�� � 㪠��⥫�� �� �㭪��
int calculateWithFunctionPtr(int a, int b, func_ptr operation) {
    return operation(a, b);
}

// std::function
int calculateWithStdFunction(int a, int b, int_operation operation) {
    return operation(a, b);
}

void task8() {
    int choice, a, b;

    // �ᯮ��㥬 safeInput ⮫쪮 ���� ࠧ
    choice = safeInput("�롥�� �������� �㭪�� (1-�, 2-���, 3-XOR): ");
    if (choice < 1 || choice > 3) {
        std::cerr << "�訡��: ������ �롮� �㭪樨.\n";
        return;
    }

    a = safeInput("������ ��ࢮ� 楫�� �᫮: ");
    b = safeInput("������ ��஥ 楫�� �᫮: ");

    int result;

    // ?? �ᯮ��㥬 std::map ��� �롮� �㭪樨
#ifdef USE_STD_FUNCTION
    std::map<int, int_operation> operations = {
        {1, andFuncPtr},
        {2, orFuncPtr},
        {3, xorFuncPtr}
    };
    result = calculateWithStdFunction(a, b, operations[choice]);
    std::cout << "������� (std::function): " << result << std::endl;
#else
    std::map<int, func_ptr> operations = {
        {1, andFuncPtr},
        {2, orFuncPtr},
        {3, xorFuncPtr}
    };
    result = calculateWithFunctionPtr(a, b, operations[choice]);
    std::cout << "������� (㪠��⥫� �� �㭪��): " << result << std::endl;
#endif
}
