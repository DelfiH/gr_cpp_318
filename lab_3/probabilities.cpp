#include <iostream>

using namespace std;

// Функция для вычисления факториала
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void calculate_probabilities() {
    // Задание a
    cout << "a) Вероятность вытянуть туза из колоды:" << endl;
    int totalCards = 52;
    int aces = 4;
    double probabilityAce = static_cast<double>(aces) / totalCards;
    cout << "P (туз) = " << probabilityAce << " или " << (probabilityAce * 100) << "%" << endl;

    // Задание b
    cout << "\nb) Вероятность суммы очков на костях равной 7:" << endl;
    int totalOutcomes = 36;
    int favorableOutcomesForSeven = 6;
    double probabilitySeven = static_cast<double>(favorableOutcomesForSeven) / totalOutcomes;
    cout << "P (сумма = 7) = " << probabilitySeven << " или " << (probabilitySeven * 100) << "%" << endl;

    // Задание c
    cout << "\nc) Вероятность составить слово 'МАМА':" << endl;
    int totalLetters = 4;
    int letterA = 2;
    int letterM = 2;
    int totalPermutations = factorial(totalLetters) / (factorial(letterA) * factorial(letterM));
    double probabilityMama = 1.0 / totalPermutations;
    cout << "P 'МАМА': " << probabilityMama
             << " или " << (probabilityMama * 100) << "%" << endl;
    }
