#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

void task2() {
    // a) �����筠� ����� 5x5
    const std::size_t size = 5;
    if (size == 0) {
        std::cerr << "�訡��: ������ ������ �� ����� ���� ࠢ�� ���.\n";
        return;
    }
    std::vector<std::vector<int>> identityMatrix(size, std::vector<int>(size, 0));

    // ������塞 �������� ������
    for (std::size_t i = 0; i < size; ++i) {
        identityMatrix[i][i] = 1;
    }

    // �뢮��� �������� ������ � ���᮫�
    std::cout << "�����筠� ����� " << size << "x" << size << ":\n";
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            std::cout << identityMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // b) ��㬥�� ���ᨢ (�����) 8x8
    const std::size_t matrixSize = 8;
    if (matrixSize == 0) {
        std::cerr << "�訡��: ������ ������ �� ����� ���� ࠢ�� ���.\n";
        return;
    }
    std::vector<std::vector<int>> randomMatrix(matrixSize, std::vector<int>(matrixSize));

    // ������塞 ������ �ᥢ����砩�묨 �᫠�� �� -15 �� 15
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // ���樠������ ������� ��砩��� �ᥫ
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = 0; j < matrixSize; ++j) {
            randomMatrix[i][j] = std::rand() % 31 - 15; // ������� �ᥫ � ��������� [-15, 15]
        }
    }

    // �뢮��� ������ � ���᮫�
    std::cout << "\n����� " << matrixSize << "x" << matrixSize << " � ��砩�묨 �᫠��:\n";
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = 0; j < matrixSize; ++j) {
            std::cout << randomMatrix[i][j] << "\t"; // �뢮� � ⠡��樥� ��� ��ࠢ�������
        }
        std::cout << std::endl;
    }

    // ��室�� �㬬� ����⮢ ������, ������ ��� ������� ���������
    long long sumAboveDiagonal = 0;
    for (std::size_t i = 0; i < matrixSize; ++i) {
        for (std::size_t j = i + 1; j < matrixSize; ++j) {
            sumAboveDiagonal += randomMatrix[i][j];
            // �஢�ઠ �� ��९������� (��樮���쭮)
            if (sumAboveDiagonal > std::numeric_limits<int>::max()) {
                std::cerr << "�।�०�����: �㬬� ����⮢ ��� ������� ��������� ����� �ਢ��� � ��९�������.\n";
            }
        }
    }

    // �뢮��� १���� ᫮�����
    std::cout << "�㬬� ����⮢ ��� ������� ���������: " << sumAboveDiagonal << std::endl;
}
