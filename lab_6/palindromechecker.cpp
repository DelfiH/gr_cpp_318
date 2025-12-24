#include "palindromechecker.h"
#include <algorithm>
#include <cctype>
#include <iostream>

PalindromeChecker::PalindromeChecker() {}

void PalindromeChecker::setInputString(const std::string& str) {
    inputString = str;
}

std::string PalindromeChecker::cleanString(const std::string& str) {
    std::string cleanedString;
    for (char c : str) {
        if (std::isalnum(c)) {
            cleanedString += std::tolower(c);
        }
    }
    return cleanedString;
}

bool PalindromeChecker::isPalindrome() {
    if (inputString.length() > MAX_LENGTH) {
        std::cout << "Ошибка: Длина строки превышает " << MAX_LENGTH << " символов." << std::endl;
        return false;
    }

    std::string cleanedString = cleanString(inputString);
    std::string reversedString = cleanedString;
    std::reverse(reversedString.begin(), reversedString.end());

    return cleanedString == reversedString;
}
