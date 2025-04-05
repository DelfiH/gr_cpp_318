/*
 * ������ୠ� ࠡ�� �2
 * ����: "��᫥������� ⨯�� ������, ���ᥬ � IDE (��⥣�஢����� �।� ࠧࠡ�⪨) QtCreator"
 * ���ࠡ��稪: ��ᨭ ��ࣥ�
 * ��㯯�: gr_cpp318
 * OS: Windows
 * locale (����஢��): ibm866
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <limits>
#include "my_functions.h" // ������砥� ���������� 䠩�

using namespace std;

// ����⠭�� ��� ���⮢
const double BROCK_MEN_COEF = 0.9;
const double BROCK_WOMEN_COEF = 0.85;
const int HEIGHT_SUBTRACTION = 100;

// ����⠭�� ��� ���ᨢ� �ᥫ � task3()
const int NUM_COUNT = 10; // ������⢮ �ᥫ � task3()


// ����⠭�� ��� ���ᨢ� �ᥫ � task4()
const double NUMBERS[] = {34.50, 0.004000, 123.005, 146000}; // ��᫠ ��� ������� 4
const int NUMBERS_SIZE = sizeof(NUMBERS) / sizeof(NUMBERS[0]); // ������ ���ᨢ� NUMBERS

// ����⠭�� ��� �롮� ����
enum Gender {
    GENDER_MALE = 1,
    GENDER_FEMALE = 0
};

// ����⠭�� ��� �롮� �����
enum Task {
    TASK_1 = 1,
    TASK_2,
    TASK_3,
    TASK_4,
    TASK_5,
    TASK_6,
    TASK_7,
    TASK_8,
    TASK_9,
    TASK_10,
    TASK_11,
    EXIT = 0
};

/**
 * ������� 1: �������� ��� ���� �����쭮�� ���
 */
void task1() {
    cout << "������� 1: �������� ��� ���� �����쭮�� ���" << endl;
    int age, height, weight, gender;
    cout << "������ ������ � ������ Enter ��� �த�������: ";
    cin >> age;
    cout << "������ ��� (� �) � ������ Enter ��� �த�������: ";
    cin >> height;
    cout << "������ ��� (� ��) � ������ Enter ��� �த�������: ";
    cin >> weight;
    cout << "�᫨ �� ��稭�, ������ " << GENDER_MALE << ". �᫨ ���騭�, ������ " << GENDER_FEMALE << " � ������ Enter ��� �த�������: ";
    cin >> gender;

    // ���㫠 �ப�
    double idealWeightBrock = (gender == GENDER_MALE)
                                ? (height - HEIGHT_SUBTRACTION) * BROCK_MEN_COEF
                                : (height - HEIGHT_SUBTRACTION) * BROCK_WOMEN_COEF;

    // ������ ����� ⥫� (BMI)
    double bmi = weight / pow(height / 100.0, 2);

    // �뢮� १����
    cout << "��� ������� ��� �� ��㫥 �ப�: " << idealWeightBrock << " ��" << endl;
    cout << "��� ������ ����� ⥫� (BMI): " << bmi << endl;

    // �������� BMI
    if (bmi < 16)
        cout << "�������: ��ࠦ���� ����� �����" << endl;
    else if (bmi < 18.5)
        cout << "�������: �������筠� ���� ⥫�" << endl;
    else if (bmi < 25)
        cout << "�������: ��ଠ" << endl;
    else if (bmi < 30)
        cout << "�������: �����筠� ���� ⥫�" << endl;
    else if (bmi < 35)
        cout << "�������: ���७�� ��ࢮ� �⥯���" << endl;
    else if (bmi < 40)
        cout << "�������: ���७�� ��ன �⥯���" << endl;
    else
        cout << "�������: ���७�� ���쥩 �⥯���" << endl;

    cout << "----------------------------------------" << endl;
}

/**
 * ������� 2: ������� ⨯�� ������ � �� ���������
 */
void task2() {
    cout << "������� 2: ������� �᭮���� ⨯�� ������ � �� ���������" << endl;


    // �뢮� ࠧ��஢ �᭮���� ⨯�� ������
    std::cout << "������� �᭮���� ⨯�� ������ (� �����):\n";
    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";

    // �뢮� ࠧ��஢ ������஢����� ⨯�� ������
    std::cout << "\n������� ������஢����� ⨯�� ������ (� �����):\n";
    std::cout << "unsigned int: " << sizeof(unsigned int) << " bytes\n";
    std::cout << "signed int: " << sizeof(signed int) << " bytes\n";
    std::cout << "short int: " << sizeof(short int) << " bytes\n";
    std::cout << "long int: " << sizeof(long int) << " bytes\n";
    std::cout << "long long int: " << sizeof(long long int) << " bytes\n";
    std::cout << "unsigned long long: " << sizeof(unsigned long long) << " bytes\n";

    // �뢮� ���������� ������ � hex, dec, bin
    std::cout << "\n��������� �᫮��� ⨯�� ������:\n";
    std::cout << "�������� int:\n";
    std::cout << "DEC: �� " << INT_MIN << " �� " << INT_MAX << "\n";
    std::cout << "HEX: �� " << std::hex << INT_MIN << " �� " << INT_MAX << "\n";
    std::cout << "BIN: (������㯭� � �⠭���⭮� ������⥪�, �㦭� ॠ�����뢠�� ������)\n";

    std::cout << "\n�������� unsigned int:\n";
    std::cout << "DEC: �� 0 �� " << UINT_MAX << "\n";
    std::cout << "HEX: �� " << std::hex << 0 << " �� " << UINT_MAX << "\n";

    std::cout << "\n�������� short int:\n";
    std::cout << "DEC: �� " << std::dec << SHRT_MIN << " �� " << SHRT_MAX << "\n";
    std::cout << "HEX: �� " << std::hex << SHRT_MIN << " �� " << SHRT_MAX << "\n";

    std::cout << "\n�������� long int:\n";
    std::cout << "DEC: �� " << std::dec << LONG_MIN << " �� " << LONG_MAX << "\n";
    std::cout << "HEX: �� " << std::hex << LONG_MIN << " �� " << LONG_MAX << "\n";

    std::cout << "\n�������� long long int:\n";
    std::cout << "DEC: �� " << std::dec << LLONG_MIN << " �� " << LLONG_MAX << "\n";
    std::cout << "HEX: �� " << std::hex << LLONG_MIN << " �� " << LLONG_MAX << "\n";

    cout << "----------------------------------------" << endl;
}

/**
 * ������� 3: �।��� ��䬥��᪮� 10 �ᥫ � ������饩 �窮�
 */
void task3() {
    cout << "������� 3: �।��� ��䬥��᪮� 10 �ᥫ � ������饩 �窮�" << endl;

    double numbers[NUM_COUNT], sum = 0;
    cout << "������ " << NUM_COUNT << " �ᥫ � ������饩 �窮�:" << endl;

    for (int i = 0; i < NUM_COUNT; ++i) {
        cout << "��᫮ " << (i + 1) << ": ";
        numbers[i] = safeInput(); // �ᯮ�짮����� ������᭮�� �����
        sum += numbers[i];
    }

    double average = sum / NUM_COUNT;
    cout << "�।��� ��䬥��᪮�: " << average << endl;

    cout << "----------------------------------------" << endl;
}

/**
 * ������� 4: ��ᯮ���樠�쭠� ������ �ᥫ
 */
void task4() {
    cout << "������� 4: ��ᯮ���樠�쭠� ������ �ᥫ" << endl;

    for (int i = 0; i < NUMBERS_SIZE; i++) {
        cout << "��᫮: " << NUMBERS[i] << " -> ��ᯮ���樠�쭠� ������: " << scientific << NUMBERS[i] << endl;
    }

    cout << "----------------------------------------" << endl;
}

/**
 * ������� 5: �����᪨� ��ࠦ���� � �뢮� ���祭��
 */
void task5() {
    cout << "������� 5: �����᪨� ��ࠦ����" << endl;

    // �����᪨� ��ࠦ����
    bool expr1 = (true && true) || false;
    bool expr2 = (false && true) || true;
    bool expr3 = (false && true) || false || true;
    bool expr4 = (5 > 6 || 4 > 3) && (7 > 8);
    bool expr5 = !(7 > 6 || 3 > 4);

    cout << "(true && true) || false = " << expr1 << endl;
    cout << "(false && true) || true = " << expr2 << endl;
    cout << "(false && true) || false || true = " << expr3 << endl;
    cout << "(5 > 6 || 4 > 3) && (7 > 8) = " << expr4 << endl;
    cout << "!(7 > 6 || 3 > 4) = " << expr5 << endl;

    cout << "----------------------------------------" << endl;

}

/**
 * ������� 6: �����᪨� ����⠭�� � �஢�ઠ ��ࠦ����
*/
void task6() {

    // ������ 6 �����᪨� ����⠭�
    constexpr bool A = true;
    constexpr bool B = false;
    constexpr bool C = true;
    constexpr bool D = false;
    constexpr bool E = true;
    constexpr bool F = false;

    // ������ 6 楫��᫥���� ����⠭� � ������� enum
    int X, Y, Z, W, V, U;
    cout << "������ ��ࢮ� �᫮: ";
    cin >> X;
    cout << "������ ��஥ �᫮: ";
    cin >> Y;
    cout << "������ ���� �᫮: ";
    cin >> Z;
    cout << "������ �⢥�⮥ �᫮: ";
    cin >> W;
    cout << "������ ��⮥ �᫮: ";
    cin >> V;
    cout << "������ ��⮥ �᫮: ";
    cin >> U;

    // ��ࠦ���� � �����᪨�� ����⠭⠬�
    cout << "��ࠦ���� 1: ((A && B) || (!C && (D || E)))= " << ((A && B) || (!C && (D || E))) << endl;
    cout << "��ࠦ���� 2: ((A && B) || (C && D) || (!E))= " << ((A && B) || (C && D) || (!E)) << endl;
    cout << "��ࠦ���� 3: ((A || B) && (C || D) && (E || F))= " << ((A || B) && (C || D) && (E || F)) << endl;

    // ��ࠦ���� � 楫��᫥��묨 ����⠭⠬�
    cout << "��ࠦ���� 4: ((X > Y) && (Z < W) && (V != U))= " << ((X > Y) && (Z < W) && (V != U)) << endl;
    cout << "----------------------------------------" << endl;
}
/**
 * ������� 7: �஢�ઠ ������� �� ��࣠��
*/
void task7() {

    // �����᪨� ��६���� a � b
    bool a, b;

    // ���� ���祭�� a � b
    cout << "������ ��ࢮ� �᫮ a(0 ��� 1): ";
    cin >> a;
    cout << "������ ��஥ �᫮ b(0 ��� 1): ";
    cin >> b;

    // �஢�ઠ ��ࢮ�� ������ �� ��࣠��
    bool left1 = !(a && b);
    bool right1 = (!a || !b);
    cout << "������� 1: !(a && b) == (!a || !b): " << (left1 == right1) << endl;

    // �஢�ઠ ��ண� ������ �� ��࣠��
    bool left2 = !(a || b);
    bool right2 = (!a && !b);
    cout << "������� 2: !(a || b) == (!a && !b): " << (left2 == right2) << endl;
    cout << "----------------------------------------" << endl;
}
/**
 * ������� 8: ����樨 � ��६���묨
*/
void task8() {
    int x, y, z, v;
    bool logicValue;

    // ��ࠦ���� 1: x = 3 + 4 + 5
    x = 3 + 4 + 5;  // �����뢠�� �� �᫠, १���� x = 12
    cout << "१���� 1: " << x << endl;

    // ��ࠦ���� 2: x = y = z
    y = 10; // �ਬ�୮� ���祭�� y
    z = 20; // �ਬ�୮� ���祭�� z
    x = y = z;  // ��ᢠ������ �ࠢ� ������: ᭠砫� y = z, ��⥬ x = y
    cout << "१���� 2: " << x << ", " << y << ", " << z << endl;

    // ��ࠦ���� 3: z *= ++y + 5
    y = 2;  // �ਬ�୮� ���祭�� y
    z = 3;  // �ਬ�୮� ���祭�� z
    z *= ++y + 5;  // y 㢥��稢����� �� 1, ��⥬ ���������� 5. z 㬭������� �� १����.
    cout << "१���� 3: " << z << endl;

    // ��ࠦ���� 4: logicValue = x || y && z || v
    x = 0;
    y = 0;
    z = 0;
    v = 0; // �⮡� logicValue �뫮 false, �� ��६���� ������ ���� ࠢ�� 0
    logicValue = x || (y && z) || v;
    cout << "१���� 4: " << logicValue << endl;
    cout << "----------------------------------------" << endl;
}

/**
 * ������� 9: ����� �᫠
*/
void task9() {

    const int N = 4; // n = 4, �������� �� 0 �� 2^4 = 16
        int number, shift;

        cout << "����� �᫮ (0 to " << (1 << N) - 1 << "): ";
        cin >> number;

        if (number < 0 || number >= (1 << N)) {
            cout << "��᫮ ��� ���������!" << endl;
            return;
        }

        cout << "������ �᫮ �᫮ �� ���஥ ����室��� ᤢ����� �᫮ �����: ";
        cin >> shift;

        int result = number << shift;
        cout << "�������: " << result << endl;
        cout << "������: " << bitset<16>(result) << endl;
        cout << "16� ���: " << hex << result << endl;
        cout << "8� ���: " << oct << result << endl;
        cout << "----------------------------------------" << endl;
}

/**
 * ������� 10: �ਮ��� ��ࠦ����
*/
void task10() {
    int a = 10, b = 5, k = 2;

    // ��ࠦ���� 1
    int res1 = a + b * 1 - 128 / 5;
    // �ਮ���: () -> * -> / -> + -> -
    cout << "������� 1: " << res1 << endl;

    // ��ࠦ���� 2
    int res2 = a | b >> 1;
    // �ਮ���: >> -> | (ᤢ��, ��⥬ ����⮢�� ������ OR)
    cout << "������� 2: " << res2 << endl;

    // ��ࠦ���� 3
    int res3 = a / b * k;
    // �ਮ���: / -> * (᫥�� ���ࠢ�)
    cout << "������� 3: " << res3 << endl;
    cout << "----------------------------------------" << endl;
}

/**
 * ������� 11: ��������. �� �롮� ��ਠ�⮢ ���᫥��� ��ண� ����� ��ਠ�� ���᫥��� ����� ��ன, ���� ��� �ணࠬ�� ��筥� ��᪮���� 横� ����ᠭ��!
*/
// �㭪�� ��� ��������
void calculator() {
    double num1, num2, result;
    int choice;

    while (true) {
        cout << "�롥�� ������ ���᫥���:" << endl;
        cout << "1. �������� (+)" << endl;
        cout << "2. ���⠭�� (-)" << endl;
        cout << "3. ��������� (*)" << endl;
        cout << "4. ������� (/)" << endl;
        cout << "5. ���" << endl;

        cout << "������ ᢮� �롮� �� (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "����!" << endl;
            break;
        }

        cout << "������ ��ࢮ� �᫮: ";
        cin >> num1;
        cout << "������ ��஥ �᫮: ";
        cin >> num2;

        try {
            switch (choice) {
                case 1:
                    result = num1 + num2;
                    cout << "�������: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 2:
                    result = num1 - num2;
                    cout << "�������: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 3:
                    result = num1 * num2;
                    cout << "�������: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 4:
                    if (num2 or num1 == 0) {
                        throw runtime_error("�訡��! �� ���� ����� ������!!!!!!!! ������ �����");
                        cout << "----------------------------------------" << endl;
                    }
                    result = num1 / num2;
                    cout << "�������: " << result << endl;
                    break;
                default:
                    cout << "������ �롮�. ���஡�� ᭮��" << endl;
                    cout << "----------------------------------------" << endl;
            }
        } catch (const runtime_error& e) {
            cout << "�訡��!: " << e.what() << endl;
            cout << "----------------------------------------" << endl;
        }
    }
        cout << "----------------------------------------" << endl;
}

/**
 * ���� �롮� �������
 */
int main() {
    int choice;
    while (true) {
                cout << "�롥�� ������� (1-11) ��� 0 ��� ��室�: " << endl;
                cout << "1. �������� ��� ���� �����쭮�� ���" << endl;
                cout << "2. ������� ⨯�� ������ � �� ���������" << endl;
                cout << "3. �।��� ��䬥��᪮� 10 �ᥫ � ������饩 �窮�" << endl;
                cout << "4. ��ᯮ���樠�쭠� ������ �ᥫ" << endl;
                cout << "5. �����᪨� ��ࠦ���� � �뢮� ���祭��" << endl;
                cout << "6. �����᪨� ����⠭�� � �஢�ઠ ��ࠦ����" << endl;
                cout << "7. �஢�ઠ ������� �� ��࣠��" << endl;
                cout << "8. ����樨 � ��६���묨" << endl;
                cout << "9.  ����� �᫠" << endl;
                cout << "10. �ਮ��� ��ࠦ����" << endl;
                cout << "11. ��������" << endl;
                cout << "0. ��室 �� �ணࠬ��" << endl;
                cin >> choice;

        switch (choice) {
            case TASK_1:
                task1();
                break;
            case TASK_2:
                task2();
                break;
            case TASK_3:
                task3();
                break;
            case TASK_4:
                task4();
                break;
            case TASK_5:
                task5();
                break;
            case TASK_6:
                task6();
                break;
            case TASK_7:
                task7();
                break;
            case TASK_8:
                task8();
                break;
            case TASK_9:
                task9();
                break;
            case TASK_10:
                task10();
                break;
            case TASK_11:
                calculator();
                break;
            case EXIT:
                cout << "��室 �� �ணࠬ��." << endl;
                return 0; // �����襭�� �ணࠬ��
            default:
                cout << "������ �롮�. ���஡�� ᭮��." << endl;
        }
    }

    return 0;
}
