#include "tasks.h"
#include <iostream>

// ������� 3: �뢮� ��䠢�� � ASCII �����
void task3() {
    std::cout << "��䠢�� ������� ��� ᨬ����\n������᪮�� �몠\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }
}
