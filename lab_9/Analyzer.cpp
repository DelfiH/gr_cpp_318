#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <regex>

// Функция для проверки точек с запятой
bool checkSemicolons(const std::string& line) {
    // Игнорируем строки, заканчивающиеся на '{', '}', комментарии и пустые строки
    if (line.empty() || line.find_first_not_of(" \t") == std::string::npos ||
        line.back() == '{' || line.back() == '}' || line.find("//") != std::string::npos) {
        return true;
    }

    // Проверяем, что строка заканчивается на ';'
    if (line.back() != ';') {
        std::cout << "Ошибка: Отсутствует точка с запятой в строке: " << line << std::endl;
        return false;
    }

    return true;
}

// Функция для проверки скобок
bool checkBrackets(const std::vector<std::string>& lines) {
    std::stack<char> brackets;
    for (const auto& line : lines) {
        for (char c : line) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (brackets.empty()) {
                    std::cout << "Ошибка: Лишняя закрывающая скобка в строке: " << line << std::endl;
                    return false;
                }
                char top = brackets.top();
                brackets.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    std::cout << "Ошибка: Неправильный порядок скобок в строке: " << line << std::endl;
                    return false;
                }
            }
        }
    }
    if (!brackets.empty()) {
        std::cout << "Ошибка: Незакрытые скобки" << std::endl;
        return false;
    }
    return true;
}

// Функция для проверки объявлений переменных
bool checkVariableDeclarations(const std::string& line, std::vector<std::string>& declaredVariables) {
    std::regex variableDeclarationPattern(R"((int|float|double|char|bool)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*(=\s*[^;]+)?;)");
    std::smatch match;

    if (std::regex_search(line, match, variableDeclarationPattern)) {
        std::string variableName = match[2].str();
        if (std::find(declaredVariables.begin(), declaredVariables.end(), variableName) == declaredVariables.end()) {
            declaredVariables.push_back(variableName);
            std::cout << "Объявлена переменная: " << variableName << std::endl;
        } else {
            std::cout << "Ошибка: Переменная " << variableName << " объявлена повторно" << std::endl;
            return false;
        }
    }
    return true;
}

void runCodeAnalyzer(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    bool semicolonsOk = true;
    for (const auto& l : lines) {
        if (!checkSemicolons(l)) {
            semicolonsOk = false;
        }
    }

    bool bracketsOk = checkBrackets(lines);

    std::vector<std::string> declaredVariables;
    bool variableDeclarationsOk = true;
    for (const auto& l : lines) {
        if (!checkVariableDeclarations(l, declaredVariables)) {
            variableDeclarationsOk = false;
        }
    }

    if (semicolonsOk && bracketsOk && variableDeclarationsOk) {
        std::cout << "Код прошел проверку!" << std::endl;
    } else {
        std::cout << "В коде обнаружены ошибки." << std::endl;
    }

    file.close();
}
