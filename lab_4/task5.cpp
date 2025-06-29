#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <limits>
#include <string>
#include <sstream>
#include "safeinput.h"


// ������� 5: ��������, ���������� � ���஢�� ���ᨢ� (��� �������筮� �㭪樨)
void task5() {
    int type, size;

    type = safeInput("�롥�� ⨯ ������ (1-char, 2-short, 3-int, 4-float, 5-double): ");
    size = safeInput("������ ������⢮ ����⮢ � ���ᨢ�: ");

    if (size <= 0) {
        std::cerr << "�訡��: ࠧ��� ���ᨢ� ������ ���� ������⥫��.\n";
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    switch (type) {
        case 1: {
            std::vector<char> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = 32 + std::rand() % (127 - 32); // ������� ᨬ����� �� 32 �� 126
            }
            std::cout << "���ᨢ ⨯� char:\n";
            for (char val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::vector<short> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = std::rand() % 1000; // ������� �ᥫ �� 0 �� 999
            }
            std::cout << "���ᨢ ⨯� short:\n";
            for (short val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::vector<int> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = std::rand() % 1000; // ������� �ᥫ �� 0 �� 999
            }
            std::cout << "���ᨢ ⨯� int:\n";
            for (int val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::vector<float> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = static_cast<float>(std::rand()) / RAND_MAX * 1000.0f; // ������� �ᥫ �� 0 �� 1000
            }
            std::cout << "���ᨢ ⨯� float:\n";
            for (float val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::vector<double> arr(size);
            for (std::size_t i = 0; i < static_cast<std::size_t>(size); ++i) {
                arr[i] = static_cast<double>(std::rand()) / RAND_MAX * 1000.0; // ������� �ᥫ �� 0 �� 1000
            }
            std::cout << "���ᨢ ⨯� double:\n";
            for (double val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        default: {
            std::cerr << "�訡��: �����४�� ⨯ ������.\n";
            return;
        }
    }
}
