/*
 * Лабораторная работа №2
 * Тема: "Исследование типов данных, лексем в IDE (интегрированной среде разработки) QtCreator"
 * Разработчик: Васин Сергей
 * Группа: gr_cpp318
 * OS: Windows
 * locale (кодировка): ibm866
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <limits>
#include "my_functions.h" // Подключаем заголовочный файл

using namespace std;

// Константы для расчетов
const double BROCK_MEN_COEF = 0.9;
const double BROCK_WOMEN_COEF = 0.85;
const int HEIGHT_SUBTRACTION = 100;

// Константы для массива чисел в task3()
const int NUM_COUNT = 10; // Количество чисел в task3()


// Константы для массива чисел в task4()
const double NUMBERS[] = {34.50, 0.004000, 123.005, 146000}; // Числа для задания 4
const int NUMBERS_SIZE = sizeof(NUMBERS) / sizeof(NUMBERS[0]); // Размер массива NUMBERS

// Константы для выбора пола
enum Gender {
    GENDER_MALE = 1,
    GENDER_FEMALE = 0
};

// Константы для выбора задач
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
 * Задание 1: Калькулятор для расчета идеального веса
 */
void task1() {
    cout << "Задание 1: Калькулятор для расчета идеального веса" << endl;
    int age, height, weight, gender;
    cout << "Введите возраст и нажмите Enter для продолжения: ";
    cin >> age;
    cout << "Введите рост (в см) и нажмите Enter для продолжения: ";
    cin >> height;
    cout << "Введите вес (в кг) и нажмите Enter для продолжения: ";
    cin >> weight;
    cout << "Если вы мужчина, введите " << GENDER_MALE << ". Если женщина, введите " << GENDER_FEMALE << " и нажмите Enter для продолжения: ";
    cin >> gender;

    // Формула Брока
    double idealWeightBrock = (gender == GENDER_MALE)
                                ? (height - HEIGHT_SUBTRACTION) * BROCK_MEN_COEF
                                : (height - HEIGHT_SUBTRACTION) * BROCK_WOMEN_COEF;

    // Индекс массы тела (BMI)
    double bmi = weight / pow(height / 100.0, 2);

    // Вывод результата
    cout << "Ваш идеальный вес по формуле Брока: " << idealWeightBrock << " кг" << endl;
    cout << "Ваш индекс массы тела (BMI): " << bmi << endl;

    // Интерпретация BMI
    if (bmi < 16)
        cout << "Результат: Выраженный дефицит массы" << endl;
    else if (bmi < 18.5)
        cout << "Результат: Недостаточная масса тела" << endl;
    else if (bmi < 25)
        cout << "Результат: Норма" << endl;
    else if (bmi < 30)
        cout << "Результат: Избыточная масса тела" << endl;
    else if (bmi < 35)
        cout << "Результат: Ожирение первой степени" << endl;
    else if (bmi < 40)
        cout << "Результат: Ожирение второй степени" << endl;
    else
        cout << "Результат: Ожирение третьей степени" << endl;

    cout << "----------------------------------------" << endl;
}

/**
 * Задание 2: Размеры типов данных и их диапазоны
 */
void task2() {
    cout << "Задание 2: Размеры основных типов данных и их диапазоны" << endl;


    // Вывод размеров основных типов данных
    std::cout << "Размеры основных типов данных (в байтах):\n";
    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";

    // Вывод размеров модифицированных типов данных
    std::cout << "\nРазмеры модифицированных типов данных (в байтах):\n";
    std::cout << "unsigned int: " << sizeof(unsigned int) << " bytes\n";
    std::cout << "signed int: " << sizeof(signed int) << " bytes\n";
    std::cout << "short int: " << sizeof(short int) << " bytes\n";
    std::cout << "long int: " << sizeof(long int) << " bytes\n";
    std::cout << "long long int: " << sizeof(long long int) << " bytes\n";
    std::cout << "unsigned long long: " << sizeof(unsigned long long) << " bytes\n";

    // Вывод диапазонов данных в hex, dec, bin
    std::cout << "\nДиапазоны числовых типов данных:\n";
    std::cout << "Диапазон int:\n";
    std::cout << "DEC: от " << INT_MIN << " до " << INT_MAX << "\n";
    std::cout << "HEX: от " << std::hex << INT_MIN << " до " << INT_MAX << "\n";
    std::cout << "BIN: (недоступно в стандартной библиотеке, нужно реализовывать вручную)\n";

    std::cout << "\nДиапазон unsigned int:\n";
    std::cout << "DEC: от 0 до " << UINT_MAX << "\n";
    std::cout << "HEX: от " << std::hex << 0 << " до " << UINT_MAX << "\n";

    std::cout << "\nДиапазон short int:\n";
    std::cout << "DEC: от " << std::dec << SHRT_MIN << " до " << SHRT_MAX << "\n";
    std::cout << "HEX: от " << std::hex << SHRT_MIN << " до " << SHRT_MAX << "\n";

    std::cout << "\nДиапазон long int:\n";
    std::cout << "DEC: от " << std::dec << LONG_MIN << " до " << LONG_MAX << "\n";
    std::cout << "HEX: от " << std::hex << LONG_MIN << " до " << LONG_MAX << "\n";

    std::cout << "\nДиапазон long long int:\n";
    std::cout << "DEC: от " << std::dec << LLONG_MIN << " до " << LLONG_MAX << "\n";
    std::cout << "HEX: от " << std::hex << LLONG_MIN << " до " << LLONG_MAX << "\n";

    cout << "----------------------------------------" << endl;
}

/**
 * Задание 3: Среднее арифметическое 10 чисел с плавающей точкой
 */
void task3() {
    cout << "Задание 3: Среднее арифметическое 10 чисел с плавающей точкой" << endl;

    double numbers[NUM_COUNT], sum = 0;
    cout << "Введите " << NUM_COUNT << " чисел с плавающей точкой:" << endl;

    for (int i = 0; i < NUM_COUNT; ++i) {
        cout << "Число " << (i + 1) << ": ";
        numbers[i] = safeInput(); // Использование безопасного ввода
        sum += numbers[i];
    }

    double average = sum / NUM_COUNT;
    cout << "Среднее арифметическое: " << average << endl;

    cout << "----------------------------------------" << endl;
}

/**
 * Задание 4: Экспоненциальная запись чисел
 */
void task4() {
    cout << "Задание 4: Экспоненциальная запись чисел" << endl;

    for (int i = 0; i < NUMBERS_SIZE; i++) {
        cout << "Число: " << NUMBERS[i] << " -> Экспоненциальная запись: " << scientific << NUMBERS[i] << endl;
    }

    cout << "----------------------------------------" << endl;
}

/**
 * Задание 5: Логические выражения и вывод значений
 */
void task5() {
    cout << "Задание 5: Логические выражения" << endl;

    // Логические выражения
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
 * Задание 6: Логические константы и проверка выражений
*/
void task6() {

    // Задаем 6 логических констант
    constexpr bool A = true;
    constexpr bool B = false;
    constexpr bool C = true;
    constexpr bool D = false;
    constexpr bool E = true;
    constexpr bool F = false;

    // Задаем 6 целочисленных констант с помощью enum
    int X, Y, Z, W, V, U;
    cout << "Введите первое число: ";
    cin >> X;
    cout << "Введите второе число: ";
    cin >> Y;
    cout << "Введите третье число: ";
    cin >> Z;
    cout << "Введите четвертое число: ";
    cin >> W;
    cout << "Введите пятое число: ";
    cin >> V;
    cout << "Введите шестое число: ";
    cin >> U;

    // Выражения с логическими константами
    cout << "Выражение 1: ((A && B) || (!C && (D || E)))= " << ((A && B) || (!C && (D || E))) << endl;
    cout << "Выражение 2: ((A && B) || (C && D) || (!E))= " << ((A && B) || (C && D) || (!E)) << endl;
    cout << "Выражение 3: ((A || B) && (C || D) && (E || F))= " << ((A || B) && (C || D) && (E || F)) << endl;

    // Выражение с целочисленными константами
    cout << "Выражение 4: ((X > Y) && (Z < W) && (V != U))= " << ((X > Y) && (Z < W) && (V != U)) << endl;
    cout << "----------------------------------------" << endl;
}
/**
 * Задание 7: Проверка законов де Моргана
*/
void task7() {

    // Логические переменные a и b
    bool a, b;

    // Ввод значений a и b
    cout << "Введите первое число a(0 или 1): ";
    cin >> a;
    cout << "Введите второе число b(0 или 1): ";
    cin >> b;

    // Проверка первого закона де Моргана
    bool left1 = !(a && b);
    bool right1 = (!a || !b);
    cout << "Результат 1: !(a && b) == (!a || !b): " << (left1 == right1) << endl;

    // Проверка второго закона де Моргана
    bool left2 = !(a || b);
    bool right2 = (!a && !b);
    cout << "Результат 2: !(a || b) == (!a && !b): " << (left2 == right2) << endl;
    cout << "----------------------------------------" << endl;
}
/**
 * Задание 8: Операции с переменными
*/
void task8() {
    int x, y, z, v;
    bool logicValue;

    // Выражение 1: x = 3 + 4 + 5
    x = 3 + 4 + 5;  // Складываем три числа, результат x = 12
    cout << "результат 1: " << x << endl;

    // Выражение 2: x = y = z
    y = 10; // Примерное значение y
    z = 20; // Примерное значение z
    x = y = z;  // Присваивание справа налево: сначала y = z, затем x = y
    cout << "результат 2: " << x << ", " << y << ", " << z << endl;

    // Выражение 3: z *= ++y + 5
    y = 2;  // Примерное значение y
    z = 3;  // Примерное значение z
    z *= ++y + 5;  // y увеличивается на 1, затем добавляется 5. z умножается на результат.
    cout << "результат 3: " << z << endl;

    // Выражение 4: logicValue = x || y && z || v
    x = 0;
    y = 0;
    z = 0;
    v = 0; // Чтобы logicValue было false, все переменные должны быть равны 0
    logicValue = x || (y && z) || v;
    cout << "результат 4: " << logicValue << endl;
    cout << "----------------------------------------" << endl;
}

/**
 * Задание 9: Сдвиг числа
*/
void task9() {

    const int N = 4; // n = 4, диапазон от 0 до 2^4 = 16
        int number, shift;

        cout << "Ведите число (0 to " << (1 << N) - 1 << "): ";
        cin >> number;

        if (number < 0 || number >= (1 << N)) {
            cout << "Число вне диапазона!" << endl;
            return;
        }

        cout << "Введите число число на которое необходимо сдвинуть число влево: ";
        cin >> shift;

        int result = number << shift;
        cout << "Десятичный: " << result << endl;
        cout << "Бинарный: " << bitset<16>(result) << endl;
        cout << "16й вид: " << hex << result << endl;
        cout << "8й вид: " << oct << result << endl;
        cout << "----------------------------------------" << endl;
}

/**
 * Задание 10: Приоритет выражений
*/
void task10() {
    int a = 10, b = 5, k = 2;

    // Выражение 1
    int res1 = a + b * 1 - 128 / 5;
    // Приоритет: () -> * -> / -> + -> -
    cout << "Результат 1: " << res1 << endl;

    // Выражение 2
    int res2 = a | b >> 1;
    // Приоритет: >> -> | (сдвиг, затем побитовая операция OR)
    cout << "Результат 2: " << res2 << endl;

    // Выражение 3
    int res3 = a / b * k;
    // Приоритет: / -> * (слева направо)
    cout << "Результат 3: " << res3 << endl;
    cout << "----------------------------------------" << endl;
}

/**
 * Задание 11: Калькулятор. При выборе вариантов вычисления строго писать вариант вычисления одной цифрой, иначе код программы начнет бесконечный цикл зависаний!
*/
// Функция для калькулятора
void calculator() {
    double num1, num2, result;
    int choice;

    while (true) {
        cout << "Выберите операцию вычисления:" << endl;
        cout << "1. Сложение (+)" << endl;
        cout << "2. Вычитание (-)" << endl;
        cout << "3. Умножение (*)" << endl;
        cout << "4. Деление (/)" << endl;
        cout << "5. Выйти" << endl;

        cout << "Введите свой выбор от (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Пока!" << endl;
            break;
        }

        cout << "Введите первое число: ";
        cin >> num1;
        cout << "Введите второе число: ";
        cin >> num2;

        try {
            switch (choice) {
                case 1:
                    result = num1 + num2;
                    cout << "Результат: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 2:
                    result = num1 - num2;
                    cout << "Результат: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 3:
                    result = num1 * num2;
                    cout << "Результат: " << result << endl;
                    cout << "----------------------------------------" << endl;
                    break;
                case 4:
                    if (num2 or num1 == 0) {
                        throw runtime_error("Ошибка! На ноль нельзя делить!!!!!!!! Повторите запрос");
                        cout << "----------------------------------------" << endl;
                    }
                    result = num1 / num2;
                    cout << "Результат: " << result << endl;
                    break;
                default:
                    cout << "Неверный выбор. Попробуйте снова" << endl;
                    cout << "----------------------------------------" << endl;
            }
        } catch (const runtime_error& e) {
            cout << "Ошибка!: " << e.what() << endl;
            cout << "----------------------------------------" << endl;
        }
    }
        cout << "----------------------------------------" << endl;
}

/**
 * Меню выбора заданий
 */
int main() {
    int choice;
    while (true) {
                cout << "Выберите задание (1-11) или 0 для выхода: " << endl;
                cout << "1. Калькулятор для расчета идеального веса" << endl;
                cout << "2. Размеры типов данных и их диапазоны" << endl;
                cout << "3. Среднее арифметическое 10 чисел с плавающей точкой" << endl;
                cout << "4. Экспоненциальная запись чисел" << endl;
                cout << "5. Логические выражения и вывод значений" << endl;
                cout << "6. Логические константы и проверка выражений" << endl;
                cout << "7. Проверка законов де Моргана" << endl;
                cout << "8. Операции с переменными" << endl;
                cout << "9.  Сдвиг числа" << endl;
                cout << "10. Приоритет выражений" << endl;
                cout << "11. Калькулятор" << endl;
                cout << "0. Выход из программы" << endl;
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
                cout << "Выход из программы." << endl;
                return 0; // Завершение программы
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}
