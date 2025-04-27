#include <iostream>
#include "min_max.h"
#include <iostream>
#include "min_max.h"

// �㭪�� ��� ���᪠ ���ᨬ㬠 ���� int
int find_max(int a, int b) {
    return (a > b) ? a : b;
}

// �㭪�� ��� ���᪠ �����㬠 ���� int
int find_min(int a, int b) {
    return (a < b) ? a : b;
}

// ��ॣ�㧪� �㭪樨 ��� ���᪠ ���ᨬ㬠 ���� unsigned short
unsigned short find_max(unsigned short a, unsigned short b) {
    return (a > b) ? a : b;
}

// ��ॣ�㧪� �㭪樨 ��� ���᪠ �����㬠 ���� unsigned short
unsigned short find_min(unsigned short a, unsigned short b) {
    return (a < b) ? a : b;
}

// ��ॣ�㧪� �㭪樨 ��� ���᪠ ���ᨬ㬠 � ��ண��
int find_max(int a, int b, int threshold) {
    int maximum = find_max(a, b);
    return (maximum > threshold) ? threshold : maximum;
}

// ��ॣ�㧪� �㭪樨 ��� ���᪠ �����㬠 � ��ண��
int find_min(int a, int b, int threshold) {
    int minimum = find_min(a, b);
    return (minimum < threshold) ? threshold : minimum;
}

// �㭪�� ��� ����� �ᥫ � ��宦����� �����㬠 � ���ᨬ㬠
void find_min_max() {
    int a, b;

    std::cout << "\n������ ��ࢮ� �᫮ (int): ";
    std::cin >> a;
    std::cout << "\n������ ��஥ �᫮ (int): ";
    std::cin >> b;

    std::cout << "\n���ᨬ�: " << find_max(a, b) << std::endl;
    std::cout << "\n������: " << find_min(a, b) << std::endl;

    unsigned short c, d;

    std::cout << "\n������ ��ࢮ� �᫮ (unsigned short): ";
    std::cin >> c;
    std::cout << "\n������ ��஥ �᫮ (unsigned short): ";
    std::cin >> d;

    std::cout << "\n���ᨬ�: " << find_max(c, d) << std::endl;
    std::cout << "\n������: " << find_min(c, d) << std::endl;

    int threshold;
    std::cout << "\n������ ��ண ��࠭�祭��: ";
    std::cin >> threshold;

    std::cout << "\n���ᨬ� � ��ண��: " << find_max(a, b, threshold) << std::endl;
    std::cout << "\n������ � ��ண��: " << find_min(a, b, threshold) << std::endl;
}
