#include <iostream>
#include "type_cast.h"

void demonstrate_type_cast() {
    // ������� ��६�����
    int x = 10;
    float y = 5.5f;
    double z = 20.3;
    unsigned short k = 7;

    // 1) int i = (x + y) * z + k;
    // ����� �८�ࠧ������ ⨯��
    int i_static_cast = static_cast<int>((x + y) * z) + static_cast<int>(k);
    // ���� �८�ࠧ������ ⨯��
    int i_implicit = (x + y) * z + k;

    // 2) k = x - y / z;
    // ����� �८�ࠧ������ ⨯��
    k = static_cast<unsigned short>(x - static_cast<int>(y / z));
    // ���� �८�ࠧ������ ⨯��
    k = x - y / z;

    // 3) z = x * y + z / x;
    // ����� �८�ࠧ������ ⨯��
    z = static_cast<double>(x * y) + static_cast<double>(z / x);
    // ���� �८�ࠧ������ ⨯��
    z = x * y + z / x;

    // 4) unsigned int ui = x / y + k;
    // ����� �८�ࠧ������ ⨯��
    unsigned int ui_static_cast = static_cast<unsigned int>(x / y) + static_cast<unsigned int>(k);
    // ���� �८�ࠧ������ ⨯��
    unsigned int ui_implicit = x / y + k;

    // 5) short s = x % static_cast<int>(x / y);
    // ����� �८�ࠧ������ ⨯��
    short s_static_cast = static_cast<short>(x % static_cast<int>(x / y));
    // ���� �८�ࠧ������ ⨯��
    short s_implicit = x % static_cast<int>(x / y);

    // �뢮� १���⮢
    std::cout << "����� (static_cast):" << std::endl;
    std::cout << "i = " << i_static_cast << std::endl;
    std::cout << "k = " << static_cast<unsigned short>(k) << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "ui = " << ui_static_cast << std::endl;
    std::cout << "s = " << s_static_cast << std::endl;

    std::cout << "\n���� (���ࠧ㬥���饥��):" << std::endl;
    std::cout << "i = " << i_implicit << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "ui = " << ui_implicit << std::endl;
    std::cout << "s = " << s_implicit << std::endl;
}
