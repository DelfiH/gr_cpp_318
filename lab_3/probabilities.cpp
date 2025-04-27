#include <iostream>

using namespace std;

// �㭪�� ��� ���᫥��� 䠪�ਠ��
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void calculate_probabilities() {
    // ������� a
    cout << "a) ����⭮��� ������� �㧠 �� ������:" << endl;
    int totalCards = 52;
    int aces = 4;
    double probabilityAce = static_cast<double>(aces) / totalCards;
    cout << "P (��) = " << probabilityAce << " ��� " << (probabilityAce * 100) << "%" << endl;

    // ������� b
    cout << "\nb) ����⭮��� �㬬� �窮� �� ������ ࠢ��� 7:" << endl;
    int totalOutcomes = 36;
    int favorableOutcomesForSeven = 6;
    double probabilitySeven = static_cast<double>(favorableOutcomesForSeven) / totalOutcomes;
    cout << "P (�㬬� = 7) = " << probabilitySeven << " ��� " << (probabilitySeven * 100) << "%" << endl;

    // ������� c
    cout << "\nc) ����⭮��� ��⠢��� ᫮�� '����':" << endl;
    int totalLetters = 4;
    int letterA = 2;
    int letterM = 2;
    int totalPermutations = factorial(totalLetters) / (factorial(letterA) * factorial(letterM));
    double probabilityMama = 1.0 / totalPermutations;
    cout << "P '����': " << probabilityMama
             << " ��� " << (probabilityMama * 100) << "%" << endl;
    }
