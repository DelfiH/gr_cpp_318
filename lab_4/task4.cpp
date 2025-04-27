#include "tasks.h"
#include <iostream>
#include <iomanip>

// ������� 4a: ����ਠ� (���⨢�� � ४��ᨢ��)
// ���⨢��� �㭪�� ��� ���᫥��� 䠪�ਠ��
long long factorialIterative(int n) {
    if (n < 0) {
        std::cerr << "�訡��: ����ਠ� ����⥫쭮�� �᫠ �� ��।����.\n";
        return -1; // �����頥� -1 � ��砥 �訡��
    }
    if (n > 20) {
        std::cerr << "�।�०�����: ����ਠ� �᫠ ����� 20 ����� �ਢ��� � ��९�������.\n";
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        if (result > LLONG_MAX / i) {
            std::cerr << "�訡��: ��९������� �� ���᫥��� 䠪�ਠ��.\n";
            return -1;
        }
        result *= i;
    }
    return result;
}

// �����ᨢ��� �㭪�� ��� ���᫥��� 䠪�ਠ��
long long factorialRecursive(int n) {
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
        long long result = factorialRecursive(n - 1);
        if (LLONG_MAX / n < result) {
            std::cerr << "�訡��: ��९������� �� ���᫥��� 䠪�ਠ��.\n";
            return -1;
        }
        return n * result;
    }
}

void task4a() {
    int n;
    std::cout << "������ �᫮ ��� ���᫥��� 䠪�ਠ��: ";
    std::cin >> n;

    long long iterativeResult = factorialIterative(n);
    if (iterativeResult != -1) {
        std::cout << "����ਠ� (���⨢��): " << iterativeResult << std::endl;
    }

    long long recursiveResult = factorialRecursive(n);
    if (recursiveResult != -1) {
        std::cout << "����ਠ� (४��ᨢ��): " << recursiveResult << std::endl;
    }
}

// ������� 4b: ��᫠ �������� (���⨢��)
// ���⨢��� �㭪�� ��� ���᫥��� �ᥫ ��������
int fibonacciIterative(int n) {
    if (n < 0) {
        std::cerr << "�訡��: ����� �������� ������ ���� ������⥫��.\n";
        return -1; // �����頥� -1 � ��砥 �訡��
    }
    if (n > 46) {
        std::cerr << "�।�०�����: ��᫮ �������� ����� 46 ����� �ਢ��� � ��९������� ��� int.\n";
    }
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        if (INT_MAX - a < b) {
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
    int n;
    std::cout << "������ ����� �᫠ ��������: ";
    std::cin >> n;

    int fibonacciResult = fibonacciIterative(n);
    if (fibonacciResult != -1) {
        std::cout << "��᫮ �������� (���⨢��): " << fibonacciResult << std::endl;
    }
}

void task4c() {
    int targetSum;
    std::cout << "������ ����筮� �᫮ � ������ ��ப� ��ࠬ���: ";
    std::cin >> targetSum;

    if (targetSum <= 0) {
        std::cerr << "�訡��: ����筮� �᫮ ������ ���� ������⥫��.\n";
        return;
    }

    int currentLine = 1;
    int currentSum = 1;
    int maxNumbers = 0;

    // ��।��塞 ���ᨬ��쭮� ������⢮ �ᥫ � ��ப�, �⮡� �ࠢ��쭮 ��஢����
    while ((currentLine * (currentLine + 1) / 2) <= targetSum) {
        maxNumbers = currentLine;
        currentLine++;
    }
    currentLine = 1;

    while (currentSum <= targetSum) {
        // ����塞 ������⢮ �஡���� ��। �᫠��
        int leadingSpaces = maxNumbers - currentLine;

        //�뢮��� �஡���
        for (int i = 0; i < leadingSpaces; ++i) {
            std::cout << "   "; // �� �஡��� ��� ������� ��ࠢ�������
        }

        // �뢮��� �᫠ �� currentLine �� 1
        for (int i = currentLine; i >= 1; --i) {
            std::cout << std::setw(2) << i << " ";
        }

        std::cout << std::setw(3) << currentSum << std::endl;

        currentLine++;
        currentSum = currentLine * (currentLine + 1) / 2;
    }
}
