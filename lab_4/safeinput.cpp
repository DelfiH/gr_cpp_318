#include "safeinput.h"
#include <sstream>

// �㭪�� ��� ������᭮�� ����� 楫��� �᫠ � �஢�મ�
int safeInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> value && ss.eof()) {
            break;
        } else {
            std::cerr << "�訡��: �����४�� ����. ��������, ������ 楫�� �᫮.\n";
        }
    }
    return value;
}
