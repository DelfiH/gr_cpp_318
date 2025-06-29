#include "tasks.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include "safeinput.h"

// Type aliases ��� ���襭�� �⠥����
using int_vector = std::vector<int>;
using size_type = std::size_t;

// �㭪�� ��� �����樨 �ᥢ����砩��� �ᥫ � �������� ��������� (ᮡ�⢥���� ॠ������)
int generateRandom(int minVal, int maxVal) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minVal, maxVal);
    return distrib(gen);
}


// ������� 1: ����� � ���ᨢ�� ��砩��� �ᥫ
void task1() {
    const size_type arraySize = 10;
    int_vector arr(arraySize);
    int minRange, maxRange;

    minRange = safeInput("������ �������쭮� ���祭�� ���������: ");
    maxRange = safeInput("������ ���ᨬ��쭮� ���祭�� ���������: ");

    if (minRange >= maxRange) {
        std::cerr << "�訡��: �������쭮� ���祭�� ������ ���� ����� ���ᨬ��쭮��.\n";
        return;
    }

    // 1. ���������� ���ᨢ� � �ᯮ�짮������ �������筮�� �����⬠ (����� ���ᥭ��)
    std::cout << "\n�ᯮ�짮����� �������筮�� �����⬠ (����� ���ᥭ��):\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minRange, maxRange);

    for (size_type i = 0; i < arraySize; ++i) {
        arr[i] = distrib(gen);
    }

    std::cout << "���祭�� ����⮢ ���ᨢ� (������):\n";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // ���� �����㬠 � ���ᨬ㬠 (�ᯮ��㥬 ������� STL)
    auto minMax = std::minmax_element(arr.begin(), arr.end());
    int minVal = *minMax.first;
    int maxVal = *minMax.second;

    std::cout << "�������쭮� ���祭�� ���ᨢ�: " << minVal << std::endl;
    std::cout << "���ᨬ��쭮� ���祭�� ���ᨢ�: " << maxVal << std::endl;

    // 2. ���������� ���ᨢ� � �ᯮ�짮������ ᮡ�⢥���� ॠ����樨 ����
    std::cout << "\n�ᯮ�짮����� ᮡ�⢥���� ॠ����樨 ����:\n";
    for (size_type i = 0; i < arraySize; ++i) {
        arr[i] = generateRandom(minRange, maxRange);
    }

    std::cout << "���祭�� ����⮢ ���ᨢ� (ᮡ�⢥���� ॠ������):\n";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // ���� �����㬠 � ���ᨬ㬠 (�ᯮ��㥬 ������� STL)
    minMax = std::minmax_element(arr.begin(), arr.end());
    minVal = *minMax.first;
    maxVal = *minMax.second;

    std::cout << "�������쭮� ���祭�� ���ᨢ�: " << minVal << std::endl;
    std::cout << "���ᨬ��쭮� ���祭�� ���ᨢ�: " << maxVal << std::endl;
}
