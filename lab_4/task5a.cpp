#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// �㭪�� ��� ���������� ���ᨢ� ��砩�묨 �᫠��
template <typename T>
void fillRandom(vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = static_cast<T>(rand()) / static_cast<T>(RAND_MAX); // ������� ��砩���� �᫠ �� 0 �� 1
    }
}

// �㭪�� ���஢�� ����쪮�
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// �㭪�� ��� �뢮�� ���ᨢ�
template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int type, n;

    cout << "�롥�� ⨯ ������ ���ᨢ�:" << endl;
    cout << "1 - char, 2 - short, 3 - int, 4 - float, 5 - double" << endl;
    cout << "��� �롮�: ";
    cin >> type;

    cout << "������ ������⢮ ����⮢ � ���ᨢ�: ";
    cin >> n;

    srand(time(0)); // ���樠������ ������� ��砩��� �ᥫ

    switch (type) {
        case 1: {
            vector<char> arr(n);
            fillRandom(arr);
            cout << "��室�� ���ᨢ: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "�����஢���� ���ᨢ: ";
            printArray(arr);
            break;
        }
        case 2: {
            vector<short> arr(n);
            fillRandom(arr);
            cout << "��室�� ���ᨢ: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "�����஢���� ���ᨢ: ";
            printArray(arr);
            break;
        }
        case 3: {
            vector<int> arr(n);
            fillRandom(arr);
            cout << "��室�� ���ᨢ: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "�����஢���� ���ᨢ: ";
            printArray(arr);
            break;
        }
        case 4: {
            vector<float> arr(n);
            fillRandom(arr);
            cout << "��室�� ���ᨢ: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "�����஢���� ���ᨢ: ";
            printArray(arr);
            break;
        }
        case 5: {
            vector<double> arr(n);
            fillRandom(arr);
            cout << "��室�� ���ᨢ: ";
            printArray(arr);
            bubbleSort(arr);
            cout << "�����஢���� ���ᨢ: ";
            printArray(arr);
            break;
        }
        default:
            cout << "������ �롮� ⨯� ������." << endl;
            return 1;
    }

    return 0;
}
