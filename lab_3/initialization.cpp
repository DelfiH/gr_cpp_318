#include <iostream>
#include "initialization.h"

// ������쭠� ��६�����
int iValue = 10;

// �㭪�� ��� ��������樨 ࠧ����� ⨯�� ���樠����樨
    void demonstrate_initialization() {
    // �����쭠� ��६����� � ⥬ �� ������, �� � ������쭠�
    int iValue = 50;

    // ��������� ���樠������
    int copyInit = ::iValue; // �ᯮ��㥬 ��������� iValue

    // ��ﬠ� ���樠������
    int directInit(20);

    // �����஢����� ���樠������
    int uniformInit{30};

    // ���-���樠������
    auto autoInit = 40;

    // �뢮� ���祭��
    std::cout << "\n�����쭠� iValue: " << iValue << std::endl;
    std::cout << "������쭠� iValue: " << ::iValue << std::endl;
    std::cout << "\n��������� ���樠������: " << copyInit << std::endl;
    std::cout << "\n��ﬠ� ���樠������: " << directInit << std::endl;
    std::cout << "\n�����஢����� ���樠������: " << uniformInit << std::endl;
    std::cout << "\n���-���樠������: " << autoInit << std::endl;

    // ���樠������ ��㣨� ⨯��
    bool bValue{true};
    char cValue{'A'};
    long lValue{123456789L};

    std::cout << "\nBValue: " << bValue << std::endl;
    std::cout << "\nCValue: " << cValue << std::endl;
    std::cout << "\nLValue: " << lValue << std::endl;
}
