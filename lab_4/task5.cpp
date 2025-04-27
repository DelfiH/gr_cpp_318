#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
// ������� 5: ��������, ���������� � ���஢�� ���ᨢ� (��� �������筮� �㭪樨)
void task5() {
    int type, size;

    std::cout << "�롥�� ⨯ ������ (1-char, 2-short, 3-int, 4-float, 5-double): ";
    std::cin >> type;

    std::cout << "������ ������⢮ ����⮢ � ���ᨢ�: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "�訡��: ࠧ��� ���ᨢ� ������ ���� ������⥫��.\n";
        return;
    }

    srand(time(0));

    switch (type) {
        case 1: {
            std::vector<char> arr(size);
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 256;
            }
            // ����஢�� ����쪮� (�ਬ��)
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }
            std::cout << "�����஢���� ���ᨢ (char):\n";
            for (char val : arr) {
                std::cout << (int)val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::vector<short> arr(size);
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 32768;
            }
            // ����஢�� �롮஬ (�ਬ��)
            for (int i = 0; i < size - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < size; ++j) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                std::swap(arr[i], arr[minIndex]);
            }
            std::cout << "�����஢���� ���ᨢ (short):\n";
            for (short val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::vector<int> arr(size);
            for (int i = 0; i < size; ++i) {
                arr[i] = rand();
            }
            // ����஢�� ��⠢���� (�ਬ��)
            for (int i = 1; i < size; ++i) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
            std::cout << "�����஢���� ���ᨢ (int):\n";
            for (int val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::vector<float> arr(size);
            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            }
            // ����஢�� ��६�訢����� (Shaker Sort) (�ਬ��)
            int left = 0;
            int right = size - 1;
            bool swapped = true;

            while (swapped) {
                swapped = false;
                for (int i = left; i < right; ++i) {
                    if (arr[i] > arr[i + 1]) {
                        std::swap(arr[i], arr[i + 1]);
                        swapped = true;
                    }
                }
                --right;
                if (!swapped) break;
                swapped = false;
                for (int i = right; i > left; --i) {
                    if (arr[i] < arr[i - 1]) {
                        std::swap(arr[i], arr[i - 1]);
                        swapped = true;
                    }
                }
                ++left;
            }
            std::cout << "�����஢���� ���ᨢ (float):\n";
            for (float val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::vector<double> arr(size);
            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            }
            // ������ ���஢�� (Quicksort) (�ਬ��)
            std::function<void(std::vector<double>&, int, int)> quickSort =
                [&](std::vector<double>& arr, int low, int high) {
                if (low < high) {
                    double pivot = arr[high];
                    int i = (low - 1);

                    for (int j = low; j <= high - 1; ++j) {
                        if (arr[j] < pivot) {
                            ++i;
                            std::swap(arr[i], arr[j]);
                        }
                    }
                    std::swap(arr[i + 1], arr[high]);

                    int partitionIndex = (i + 1);

                    quickSort(arr, low, partitionIndex - 1);
                    quickSort(arr, partitionIndex + 1, high);
                }
            };
            quickSort(arr, 0, size - 1);

            std::cout << "�����஢���� ���ᨢ (double):\n";
            for (double val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
            break;
        }
        default:
            std::cout << "������ ⨯ ������.\n";
            break;
    }
}
