#include <iostream>
#include <iomanip> // ��� �ଠ�஢���� �뢮��

int main() {
        std::cout << std::setw(65) << "������� 1" << std::endl; // �뢮� ���ଠ樨 � ᥡ�
        std::cout << std::endl << "����� ��㯯�: 318, 䠪����: ���. ��ࠧ������" << std::endl; //�뢮� ���ଠ樨 �  ����� ��㯯�, 䠪����
        std::cout << "���ࠡ��稪� �ணࠬ��:" << std::endl << "1. ��ᨭ ��ࣥ�" << std::endl; //�뢮� 䠬���� � ����� ࠧࠡ��稪� �ணࠬ��
        std::cout << "����� ������୮� ࠡ���: 1" << std::endl; //�뢮�

        std::cout << std::endl << std::setw(65) << "������� 2" << std::endl; // �뢮� ���ଠ樨 � ᥡ�
        std::cout << std::endl << "*****" << std::setw(58) << "�����" << std::setw(57)  << "*****" << std::endl;
        std::cout << std::endl << std::right << std::setw(117) << "�������: ���.��ࠧ������" << std::endl;
        std::cout << std::setw(102) << "��㯯�: 318" << std::endl;
        std::cout << std::setw(112) << "��㤥��: ��ᨭ ��ࣥ�" << std::endl;
        std::cout << std::endl << std::setw(66) << "���� 2025" << std::endl;

        std::cout << std::endl << std::setw(65) << "������� 3" << std::endl; // ����� �� ���᫥��� ��।�������� ���祭��

    double Distance, Time, Speed; // ��६���� � Pascal case
        std::cout << std::endl << std::setw(80) << "���᫥��� ᪮��� ��אַ��������� ��������." << std::endl; //  ���᫥��� ᪮��� ��אַ��������� ��������
        std::cout << std::endl << "������ ����ﭨ� (�): "; // ���� ���祭�� ����ﭨ�
        std::cin >> Distance; // �뢮� १���� ���⠭樨
        std::cout << "������ �६� (�): "; // ���� ���祭�� �६���
        std::cin >> Time; // �뢮� १���� �६���
        Speed = Distance / Time; // ���㫠 ���᫥��� ᪮��� ��אַ��������� ��������
        std::cout << "������� ��אַ��������� ��������: " << Speed << " �/�" << std::endl; // �뢮� १���� ᪮��� ��אַ��������� ��������

    double InitialSpeed, FinalSpeed, Acceleration; // ��६���� � Pascal case
        std::cout << std::endl << std::setw(72)<< "���᫥��� �᪮७��." << std::endl; // ���᫥��� �᪮७��
        std::cout << std::endl << "������ ��砫��� ᪮���� (�/�): "; // ���� ��砫쭮� ᪮���
        std::cin >> InitialSpeed; // �뢮� ���祭�� ��砫쭮� ᪮���
        std::cout << "������ ������� ᪮���� (�/�): "; // ���� ����筮� ᪮���
        std::cin >> FinalSpeed; // �뢮� ���������� ���祭�� ����筮� ᪮���
        std::cout << "������ �६� (�): "; // ���� �६���
        std::cin >> Time; // �뢮� ���������� ���祭�� �६�
        Acceleration = (FinalSpeed - InitialSpeed) / Time; // ���㫠 ���᫥��� �᪮७��
        std::cout << "�᪮७��: " << Acceleration << " �/�" << std::endl; // �뢮� १���� ���᫥��� �᪮७��

    double Circumference, Radius; // ��६���� � Pascal case
        std::cout << std::endl << std::setw(74) << "���᫥��� ࠤ��� ��㣠." << std::endl; // ���᫥��� ࠤ��� ��㣠
        std::cout << std::endl << "������ ����� ���㦭��� (�): "; // ���� ����� ���㦭���
        std::cin >> Circumference; // �뢮� ���������� ���祭�� ����� ���㦭���
        Radius = Circumference / (2 * 3.14); // �ᯮ��㥬 ���祭�� 3.14
        std::cout << "������ ��㣠: " << Radius << " �" << std::endl; // �뢮� १���� ࠤ��� ��㣠
        std::cout << std::endl << "������ ������� Enter ��� ������� �ணࠬ��" << std::endl; // ������ �� ������� Enter ���� ������� ����
    return 0; // �����⨥ �ணࠬ��
}
    // ��ꥬ *.exe 䠩�� � ०��� Release: 49 ��
    // ��ꥬ *.exe 䠩�� � ०��� Debug: 70 ��



