#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void task2() {
    // a) �����筠� ����� 5x5
    const int size = 5;
    std::vector<std::vector<int>> identityMatrix(size, std::vector<int>(size, 0));

    // ������塞 �������� ������
    for (int i = 0; i < size; ++i) {
        identityMatrix[i][i] = 1;
    }

    // �뢮��� �������� ������ � ���᮫�
    std::cout << "�����筠� ����� " << size << "x" << size << ":\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << identityMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // b) ��㬥�� ���ᨢ (�����) 8x8
    const int matrixSize = 8;
    std::vector<std::vector<int>> randomMatrix(matrixSize, std::vector<int>(matrixSize));

    // ������塞 ������ �ᥢ����砩�묨 �᫠�� �� -15 �� 15
    srand(time(0)); // ���樠������ ������� ��砩��� �ᥫ
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            randomMatrix[i][j] = rand() % 31 - 15; // ������� �ᥫ � ��������� [-15, 15]
        }
    }

    // �뢮��� ������ � ���᮫�
    std::cout << "\n����� " << matrixSize << "x" << matrixSize << " � ��砩�묨 �᫠��:\n";
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << randomMatrix[i][j] << "\t"; // �뢮� � ⠡��樥� ��� ��ࠢ�������
        }
        std::cout << std::endl;
    }

    // ��室�� �㬬� ����⮢ ������, ������ ��� ������� ���������
    int sumAboveDiagonal = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = i + 1; j < matrixSize; ++j) {
            sumAboveDiagonal += randomMatrix[i][j];
        }
    }

    // �뢮��� १���� ᫮�����
    std::cout << "�㬬� ����⮢ ��� ������� ���������: " << sumAboveDiagonal << std::endl;
}
