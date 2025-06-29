#include "tasks.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <type_traits>
#include "safeinput.h"

// Type aliases ��� 㤮��⢠ � �⠥����
using IndexType = std::size_t;
using IntType = int;
using LongLongType = long long;


// ������� 4a: ����ਠ� (���⨢�� � ४��ᨢ��)
// ���⨢��� �㭪�� ��� ���᫥��� 䠪�ਠ��
LongLongType factorialIterative(IntType n) {
    if (n < 0) {
        std::cerr << "�訡��: ����ਠ� ����⥫쭮�� �᫠ �� ��।����.\n";
        return -1; // �����頥� -1 � ��砥 �訡��
    }
    if (n > 20) {
        std::cerr << "�।�०�����: ����ਠ� �᫠ ����� 20 ����� �ਢ��� � ��९�������.\n";
    }
    LongLongType result = 1;
    for (IndexType i = 1; i <= static_cast<IndexType>(n); ++i) {
        if (result > std::numeric_limits<LongLongType>::max() / static_cast<LongLongType>(i)) {
            std::cerr << "�訡��: ��९������� �� ���᫥��� 䠪�ਠ��.\n";
            return -1;
        }
        result *= static_cast<LongLongType>(i);
    }
    return result;
}

// �����ᨢ��� �㭪�� ��� ���᫥��� 䠪�ਠ��
LongLongType factorialRecursive(IntType n) {
    if (n < 0) {
        std::cerr << "�訡��: ����ਠ� ����⥫쭮�� �᫠ �� ��।����.\n";
        return -1; // �����頥� -1 � ��砥 �訡��
    }
    if (n > 20) {
        std::cerr << "�।�०�����: ����ਠ� �᫠ ����� 20 ����� �ਢ��� � ��९�������.\n";
    }
    if (n == 0) {
        return 1;
    } else {
        LongLongType result = factorialRecursive(n - 1);
        if (std::numeric_limits<LongLongType>::max() / n < result) {
            std::cerr << "�訡��: ��९������� �� ���᫥��� 䠪�ਠ��.\n";
            return -1;
        }
        return static_cast<LongLongType>(n) * result;
    }
}

void task4a() {
    IntType n = safeInput("������ �᫮ ��� ���᫥��� 䠪�ਠ��: ");

    LongLongType iterativeResult = factorialIterative(n);
    if (iterativeResult != -1) {
        std::cout << "����ਠ� (���⨢��): " << iterativeResult << std::endl;
    }

    LongLongType recursiveResult = factorialRecursive(n);
    if (recursiveResult != -1) {
        std::cout << "����ਠ� (४��ᨢ��): " << recursiveResult << std::endl;
    }
}

// ������� 4b: ��᫠ �������� (���⨢��)
// ���⨢��� �㭪�� ��� ���᫥��� �ᥫ ��������
IntType fibonacciIterative(IntType n) {
    if (n < 0) {
        std::cerr << "�訡��: ����� �������� ������ ���� ������⥫��.\n";
        return -1; // �����頥� -1 � ��砥 �訡��
    }
    if (n > 46) {
        std::cerr << "�।�०�����: ��᫮ �������� ����� 46 ����� �ਢ��� � ��९������� ��� int.\n";
    }
    if (n <= 1) return n;
    IntType a = 0, b = 1, temp;
    for (IndexType i = 2; i <= static_cast<IndexType>(n); ++i) {
        if (std::numeric_limits<IntType>::max() - a < b) {
            std::cerr << "�訡��: ��९������� �� ���᫥��� �᫠ ��������.\n";
            return -1;
        }
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

void task4b() {
    IntType n = safeInput("������ ����� �᫠ ��������: ");

    IntType fibonacciResult = fibonacciIterative(n);
    if (fibonacciResult != -1) {
        std::cout << "��᫮ �������� (���⨢��): " << fibonacciResult << std::endl;
    }
}

void task4c() {
    IntType targetSum = safeInput("������ ����筮� �᫮ � ������ ��ப� ��ࠬ���: ");

    if (targetSum <= 0) {
        std::cerr << "�訡��: ����筮� �᫮ ������ ���� ������⥫��.\n";
        return;
    }

    IntType currentLine = 1;
    IntType currentSum = 1;
    IntType maxNumbers = 0;

    // ��।��塞 ���ᨬ��쭮� ������⢮ �ᥫ � ��ப�, �⮡� �ࠢ��쭮 ��஢����
    while ((currentLine * (currentLine + 1) / 2) <= targetSum) {
        maxNumbers = currentLine;
        currentLine++;
    }
    currentLine = 1;

    while (currentSum <= targetSum) {
        // ����塞 ������⢮ �஡���� ��। �᫠��
        IntType leadingSpaces = maxNumbers - currentLine;

        // �뢮��� �஡���
        for (IndexType i = 0; i < static_cast<IndexType>(leadingSpaces); ++i) {
            std::cout << "   "; // �� �஡��� ��� ������� ��ࠢ�������
        }

        // �뢮��� �᫠ �� currentLine �� 1
        for (IntType i = currentLine; i >= 1; --i) {
            std::cout << std::setw(2) << i << " ";
        }

        std::cout << std::setw(3) << currentSum << std::endl;

        currentLine++;
        currentSum = currentLine * (currentLine + 1) / 2;
    }
}
