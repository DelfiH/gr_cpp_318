#include "tasks.h"
#include <iostream>
#include <limits>
#include <type_traits>

// Type aliases ��� 㤮��⢠ � �⠥����
using IndexType = std::size_t;
using CharType = char;
using IntType = int;

// ������� 3: �뢮� ��䠢�� � ASCII �����
void task3() {
    std::cout << "��䠢�� ������� ��� ᨬ����\n������᪮�� �몠\n";
    constexpr IndexType alphabetSize = 26; // ������ ������᪮�� ��䠢��

    // "���� �� ��ࠪ�": �஢�ઠ, �� alphabetSize �� �ॢ�蠥� ࠧ��� ��䠢��
    if (alphabetSize > std::numeric_limits<CharType>::max() - 'a') {
        std::cerr << "�訡��: alphabetSize ᫨誮� �����.\n";
        return;
    }

    for (IndexType i = 0; i < alphabetSize; ++i) {
        CharType c = 'a' + static_cast<CharType>(i);
        IntType asciiCode = static_cast<IntType>(c);
        std::cout << c << " " << asciiCode << std::endl;
    }
}
