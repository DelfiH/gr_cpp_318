#include "tasks.h"
#include <iostream>

// ������� 6a: �����⥫� � ����
void task6a() {
    int m;
    float fx;
    char cht;

    std::cout << "�����⥫�: �த�������஢��� �ᯮ�짮����� �����஢ & � *\n";
    std::cout << "------------------------------------------------------\n";

    std::cout << "������ 楫�� �᫮ m: ";
    std::cin >> m;
    std::cout << "������ �᫮ � ������饩 �窮� fx: ";
    std::cin >> fx;
    std::cout << "������ ᨬ��� cht: ";
    std::cin >> cht;

    std::cout << "m = " << m << std::endl;
    std::cout << "fx = " << fx << std::endl;
    std::cout << "cht = " << cht << std::endl;

    std::cout << "\n�ᯮ�짮����� & ������:\n";
    std::cout << "----------------------\n";
    std::cout << "���� m = " << &m << std::endl;
    std::cout << "���� fx = " << &fx << std::endl;
    std::cout << "���� cht = " << &cht << std::endl;

    std::cout << "\n�ᯮ���� ������� & � *:\n";
    std::cout << "-----------------------------\n";
    std::cout << "���祭�� �� ����� m = " << *(&m) << std::endl;
    std::cout << "���祭�� �� ����� fx = " << *(&fx) << std::endl;
    std::cout << "���祭�� �� ����� cht = " << *(&cht) << std::endl;

    std::cout << "\n�ᯮ���� ⮫쪮 ��६����� 㪠��⥫�:\n";
    std::cout << "----------------------------------\n";
    int* ptr_m = &m;
    float* ptr_fx = &fx;
    char* ptr_cht = &cht;

    std::cout << "���� m = " << ptr_m << std::endl;
    std::cout << "���� fx = " << ptr_fx << std::endl;
    std::cout << "���� cht = " << ptr_cht << std::endl;

    std::cout << "\n�ᯮ�짮����� ⮫쪮 ������ 㪠��⥫�:\n";
    std::cout << "----------------------------------\n";
    std::cout << "���祭�� �� ����� m = " << *ptr_m << std::endl;
    std::cout << "���祭�� �� ����� fx = " << *ptr_fx << std::endl;
    std::cout << "���祭�� �� ����� cht = " << *ptr_cht << std::endl;
}

// ������� 6b: �࠭���� � ����� ����⮢ ���ᨢ� � ������� 㪠��⥫�
void task6b() {
    int n;
    std::cout << "������ ������⢮ ����⮢ � ���ᨢ�: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "�訡��: ࠧ��� ���ᨢ� ������ ���� ������⥫��.\n";
        return;
    }

    int* arr = new int[n]; // �������᪮� �뤥����� �����

    std::cout << "������ ������ ���ᨢ�:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "�������� ���ᨢ�, �����⠭�� � ������� 㪠��⥫�:\n";
    int* ptr = arr; // �����⥫� �� ��砫� ���ᨢ�
    for (int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = " << *ptr << " (����: " << ptr << ")\n";
        ++ptr; // ��६�頥� 㪠��⥫� �� ᫥���騩 �����
    }

    delete[] arr; // �᢮�������� �뤥������ �����
    arr = nullptr; // ��⠭�������� 㪠��⥫� � nullptr, �⮡� �������� "������" 㪠��⥫��
}
