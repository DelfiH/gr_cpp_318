#ifndef PALINDROMECHECKER_H
#define PALINDROMECHECKER_H

#include <string>

class PalindromeChecker {
private:
    std::string inputString;
    const int MAX_LENGTH = 17;

    std::string cleanString(const std::string& str);

public:
    PalindromeChecker();
    void setInputString(const std::string& str);
    bool isPalindrome();
};

#endif
