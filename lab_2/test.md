1. Найдите в программе ошибки, представите ниже рабочий вариант программы. 

НЕПРАВИЛЬНЫЙ КОД:
nt main() {
short a;
a(65599);
int 5 = 4;
int л = 4;
char ch;
ch{5};
float f;
f = 3,2;
}}

ИСПРАВЛЕННЫЙ КОД:

#include <iostream>
int main() {
    short a;
    a = 65599; // Присваиваем значение
    int x = 4; // Имя переменной не может быть числом
    int l = 4; // Рекомендуется использовать латиницу
    char ch;
    ch = 5; // Корректная инициализация
    float f;
    f = 3.2; // Дробные числа через точку
    return 0;
}

2. Какие значения выводит эта программа?
а) НЕПРАВИЛЬНЫЙ КОД:

#include <iostream>
int main() {
int x = 5;
x = x - 2;
//a
std::cout << x << std::endl; // #a
int y = x;
//b
std::cout << y << std::endl; // #b
//c
std::cout << x + y << std::endl; // #c
//d
std::cout << x << std::endl; // #d
int z;
//e
std::cout << z << std::endl; // #e

ИСПРАВЛЕННЫЙ КОД:

#include <iostream>
int main() {
    int x = 5;
    x = x - 2; // x = 3
    std::cout << x << std::endl; // a) 3
    int y = x; // y = 3
    std::cout << y << std::endl; // b) 3
    std::cout << x + y << std::endl; // c) 6
    std::cout << x << std::endl; // d) 3
    int z; // z не инициализирован
    std::cout << z << std::endl; // e) Неопределённое значение
}

//Переменная z не инициализирована, и её значение не определено. Поэтому она может выводить случайные значения из памяти. // 

b) НЕПРАВИЛЬНЫЙ КОД:
#include <iostream>
int main() {
int x = 1;
x = x++;

std::cout << x << "\n"; // Выведет: 1
}

// Постфиксный инкремент x++ возвращает старое значение переменной и увеличивает его после выполнения выражения. Однако, в данном случае, результат увеличения не используется, поэтому значение x остаётся равным 1 //

ИСПРАВЛЕННЫЙ КОД:

#include <iostream>
int main() {
    int x = 1;
    x = x++; // Постфиксный инкремент возвращает старое значение x, а затем увеличивает его
    std::cout << x << "\n"; // Выведет: 1
}

// Постфиксный инкремент x++ возвращает старое значение переменной и увеличивает его после выполнения выражения. Однако, в данном случае, результат увеличения не используется, поэтому значение x остаётся равным 1 //

c) НЕПРАВИЛЬНЫЙ КОД:

#include <iostream>
int main(){
int x = 1;
std::cout << ++x << "\n";
}

ИСПРАВЛЕННЫЙ КОД:

#include <iostream>
int main() {
    int x = 1;
    std::cout << ++x << "\n"; // Префиксный инкремент возвращает увеличенное значение
    // Выведет: 2
}

// Префиксный инкремент ++x сначала увеличивает значение переменной, а затем возвращает его. //

3. Найдите в программе ошибки, можно только что-то добавлять убирать нельзя, и выведите
результат.
а) НЕПРАВИЛЬНЫЙ КОД:

const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main( {
bitset<8> bits(0x4);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);
cin << "Bit 1 has value: " << bits.test(option_1) << '/n';
cin << Bit 3 has value: " << bits.test() << '\n';
cin << "Bit 7 has value: " << bits.test() < '\n';
cin<< "All the bits: " << bits << '\n;

ПРАВИЛЬНЫЙ КОД:

#include <bitset>
#include <iostream>

const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8 = 7; // Исправлено

int main() {
    std::bitset<8> bits(0x4);
    bits.set(option_1);
    bits.flip(option_3);
    bits.reset(option_7);
    std::cout << "Bit 1 has value: " << bits.test(option_1) << '\n'; // Исправлено
    std::cout << "Bit 3 has value: " << bits.test(option_3) << '\n'; // Исправлено
    std::cout << "Bit 7 has value: " << bits.test(option_7) << '\n'; // Исправлено
    std::cout << "All the bits: " << bits << '\n'; // Исправлено
    return 0;
}

b) НЕПРАВИЛЬНЫЙ КОД:

int main()
uint8_t a(1), uint8_t b(1), c(3
a = a < 1;
printf("a: \n", a)
b <<= 1;
printf("b: \n", b);
c |= 1;
print("c: \n", );

ПРАВИЛЬНЫЙ КОД:

#include <iostream>

int main() {
    uint8_t a = 1, b = 1, c = 3; // Исправлено
    a = a < 1;
    printf("a: %d\n", a); // Исправлено
    b <<= 1;
    printf("b: %d\n", b); // Исправлено
    c |= 1;
    printf("c: %d\n", c); // Исправлено
    return 0;
}

с) НЕПРАВИЛЬНЫЙ КОД:

int main() {
int x (08);
std::cout << "x: " << x < endl;
int y = 0x5;
std::cout << "y: " < y << stdendl;
int bin(0);
bin = 0b101
out << "bin 0b101: " << bin << std::endl

ПРАВИЛЬНЫЙ КОД:

#include <iostream>

int main() {
    int x = 8; // Исправлено
    std::cout << "x: " << x << std::endl; // Исправлено
    int y = 0x5;
    std::cout << "y: " << y << std::endl; // Исправлено
    int bin = 0b101; // Исправлено
    std::cout << "bin 0b101: " << bin << std::endl; // Исправлено
    return 0;
}

d) НЕПРАВИЛЬНЫЙ КОД:

int main() {
int x{8};
std::cout << "hex: " << h << x << ndl;
std::cout << "oct: " << o<< x << std::endl;
out << "dec: " << dec << x << std::endl;
}

ПРАВИЛЬНЫЙ КОД:

#include <iostream>
#include <iomanip>

int main() {
    int x = 8;
    std::cout << "hex: " << std::hex << x << std::endl; // Исправлено
    std::cout << "oct: " << std::oct << x << std::endl; // Исправлено
    std::cout << "dec: " << std::dec << x << std::endl; // Исправлено
    return 0;
}

4 Вычислите следующие выражения:

#include <iostream>

int main() {
    // a) Логические выражения
    bool result1 = (true && true) || false; // true
    bool result2 = (false && true) || true; // true
    bool result3 = (false && true) || false || true; // true
    bool result4 = (5 > 6 || 4 > 3) && (7 > 8); // false
    bool result5 = !(7 > 6 || 3 > 4); // false

    std::cout << "Результаты логических выражений:" << std::endl;
    std::cout << "1: " << result1 << std::endl; // true
    std::cout << "2: " << result2 << std::endl; // true
    std::cout << "3: " << result3 << std::endl; // true
    std::cout << "4: " << result4 << std::endl; // false
    std::cout << "5: " << result5 << std::endl; // false

    // b) Результат 0110 >> 2 в двоичной системе счисления
    int number = 0b0110; // Двоичное представление
    int shifted = number >> 2; // Сдвиг вправо на 2 бита
    std::cout << "Результат 0110 >> 2: " << std::bitset<4>(shifted) << std::endl; // Вывод в двоичной системе

    // c) Результат 5 & 12 в десятичной системе счисления
    int andResult = 5 & 12; // Побитовое И
    std::cout << "Результат 5 & 12: " << andResult << std::endl; // Десятичный результат

    // d) Результат 5 ^ 12 в десятичной системе счисления
    int xorResult = 5 ^ 12; // Побитовое XOR
    std::cout << "Результат 5 ^ 12: " << xorResult << std::endl; // Десятичный результат

    return 0;
}

5 Конвертируйте двоичное число 0100 1101 в десятичную систему счисления.

#include <iostream>
#include <bitset>

int main() {
    // Двоичное число 0100 1101
    std::bitset<8> binaryNumber("01001101"); // Убираем пробелы для правильной инициализации
    int decimalNumber = static_cast<int>(binaryNumber.to_ulong()); // Конвертация в десятичное число

    std::cout << "Двоичное число: " << binaryNumber << std::endl;
    std::cout << "Десятичное число: " << decimalNumber << std::endl;

    return 0;
}
