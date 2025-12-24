#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//-----------------------------------------------------------------------------
// Функция для распаковки строки
//-----------------------------------------------------------------------------
string unpackString(const string& packed) {
    string result;
    for (size_t i = 0; i < packed.length(); ++i) {
        if (isdigit(packed[i])) {
            int count = packed[i] - '0'; // Преобразуем символ в число
            while (i + 1 < packed.length() && isdigit(packed[i + 1])) {
                count = count * 10 + (packed[++i] - '0');
            }
            if (i + 1 < packed.length()) {
                result += string(count, toupper(packed[++i])); // Добавляем буквы в верхнем регистре
            }
        }
    }
    return result;
}

//-----------------------------------------------------------------------------
// Функция task4 для взаимодействия с пользователем
//-----------------------------------------------------------------------------
void task4() {
    string packedStr;
    cout << "Введите упакованную строку (например, 4AB5C4D): ";
    cin >> packedStr;

    string result = unpackString(packedStr);
    cout << "Восстановленная строка: " << result << endl;
}
