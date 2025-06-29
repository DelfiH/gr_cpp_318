#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <type_traits>
#include <memory>

// Type aliases ��� ���襭�� �⠥���� � �������
using IntType = int;
using FloatType = float;
using CharType = char;
using IntPtr = IntType*;
using FloatPtr = FloatType*;
using CharPtr = CharType*;
using SizeType = std::size_t; // ��� ���稪�� � �����ᮢ

// �㭪�� ��� ������᭮�� ����� 楫��� �᫠
IntType safeIntInput(const std::string& prompt) {
    IntType value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        ss >> value;

        if (ss.fail()) {
            std::cout << "�訡��: �����४�� ����. ��������, ������ 楫�� �᫮.\n";
            ss.clear(); // <--- ��頥� ���ﭨ� �訡��
            continue; // �����塞 ����
        }
        else {
            char remaining;
            if (ss >> remaining) {
                std::cout << "�訡��: ��᫥ �᫠ �����㦥�� ��譨� ᨬ����. ��������, "
                    "������ ⮫쪮 楫�� �᫮.\n";
            }
            else {
                break; // ���� �ᯥ襭, ��室�� �� 横��
            }
        }
    }
    return value;
}
FloatType safeFloatInput(const std::string& prompt) {
    FloatType value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty()) { // �஢�ઠ �� ���⮩ ����
            std::cout << "�訡��: ���⮩ ����. ��������, ������ �᫮ � ������饩 �窮�.\n";
            continue;
        }

        std::stringstream ss(input);
        ss >> value;

        if (ss.fail()) {
            std::cout << "�訡��: �����४�� ����. ��������, ������ �᫮ � ������饩 �窮�.\n";
            ss.clear();
            continue;
        }
        // �஢�ઠ �� ����稥 ��譨� ᨬ�����
        char remaining;
        if (ss.get(remaining)) {
            std::cout << "�訡��: ��᫥ �᫠ �����㦥�� ��譨� ᨬ����. ��������, ������ ⮫쪮 �᫮ � ������饩 �窮�.\n";
            ss.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // "�ꥤ���" �� ��譨� ᨬ����
        } else {
            break; // ���� �ᯥ襭
        }
    }
    return value;
}
// �㭪�� ��� ������᭮�� ����� ᨬ����
CharType safeCharInput(const std::string& prompt) {
    CharType ch;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.length() == 1) {
            ch = input[0];
            break;
        }
        else {
            std::cout << "�訡��: �����४�� ����. ��������, ������ ���� ᨬ���.\n";
        }
    }
    return ch;
}

void task6a() {
    IntType m;
    FloatType fx;
    CharType cht;

    std::cout << "�����⥫�: �த�������஢��� �ᯮ�짮����� �����஢ & � *\n";
    std::cout << "------------------------------------------------------\n";

    m = safeIntInput("������ 楫�� �᫮ m: ");

    fx = safeFloatInput("������ �᫮ � ������饩 �窮� fx: ");

    cht = safeCharInput("������ ᨬ��� cht: ");

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
    IntPtr ptr_m = &m;
    FloatPtr ptr_fx = &fx;
    CharPtr ptr_cht = &cht;

    std::cout << "���� m = " << ptr_m << std::endl;
    std::cout << "���� fx = " << ptr_fx << std::endl;
    std::cout << "���� cht = " << ptr_cht << std::endl;

    std::cout << "\n�ᯮ�짮����� ⮫쪮 ������ 㪠��⥫�:\n";
    std::cout << "----------------------------------\n";
    std::cout << "���祭�� �� ����� m = " << *ptr_m << std::endl;
    std::cout << "���祭�� �� ����� fx = " << *ptr_fx << std::endl;
    std::cout << "���祭�� �� ����� cht = " << *ptr_cht << std::endl;
}

void task6b() {
    IntType n = safeIntInput("������ ������⢮ ����⮢ � ���ᨢ�: ");

    if (n <= 0) {
        std::cerr << "�訡��: ࠧ��� ���ᨢ� ������ ���� ������⥫��.\n";
        return;
    }

    std::unique_ptr<IntType[]> arr(new IntType[n]); // �ᯮ��㥬 unique_ptr

    std::cout << "������ ������ ���ᨢ�:\n";
    for (SizeType i = 0; i < static_cast<SizeType>(n); ++i) {
        arr[i] = safeIntInput("������� " + std::to_string(i + 1) + ": ");
    }

    std::cout << "�������� ���ᨢ�, �����⠭�� � ������� 㪠��⥫�:\n";
    IntType* ptr = arr.get(); // ����砥� "��ன" 㪠��⥫� �� unique_ptr
    for (SizeType i = 0; i < static_cast<SizeType>(n); ++i) {
        std::cout << "arr[" << i << "] = " << *ptr << " (����: " << static_cast<void*>(ptr) << ")\n";
        ++ptr; // ��६�頥� 㪠��⥫� �� ᫥���騩 �����
    }

    // ������ �㤥� �᢮������� ��⮬���᪨ �� ��室� �� ������ ��������
}
