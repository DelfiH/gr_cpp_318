#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

//-----------------------------------------------------------------------------
// Структура для хранения адреса
//-----------------------------------------------------------------------------
struct Address {
    string Country;  // Страна
    string City;     // Город
    string Street;   // Улица
    string House;    // Номер дома
};

//-----------------------------------------------------------------------------
// Объявление функций
//-----------------------------------------------------------------------------
void Parse(const string& line, Address* const address);  // Разбор строки адреса
void Unify(Address* const address);  // Приведение к единому формату
string Format(const Address& address);  // Форматирование адреса
bool isValidInput(const string& input);  // Проверка ввода

//-----------------------------------------------------------------------------
// Функция для удаления пробелов в начале и конце строки
//-----------------------------------------------------------------------------
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";  // Строка состоит только из пробелов
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

//-----------------------------------------------------------------------------
// Главная функция для обработки адресов
//-----------------------------------------------------------------------------
void task8() {
    cout << "Введите страну, город, улицу и номер дома/квартиры" << endl;

    string line;
    Address* address = new Address;  // Выделяем память для структуры Address

    // Читаем строки из ввода до конца
    while (getline(cin, line)) {
        line = trim(line);  // Удаляем лишние пробелы
        if (line.empty()) continue;  // Пропускаем пустые строки

        try {
            Parse(line, address);  // Разбираем строку адреса
            Unify(address);        // Приводим адрес к единому формату
            cout << Format(*address) << "\n";  // Выводим отформатированный адрес
        } catch (const exception& e) {
            cout << "exception: " << e.what() << "\n";  // Обработка ошибок
        }
    }

    delete address;     // Освобождаем выделенную память
    address = nullptr;  // Обнуляем указатель, чтобы избежать проблем
}

//-----------------------------------------------------------------------------
// Функция для разбора строки адреса
//-----------------------------------------------------------------------------
void Parse(const string& line, Address* const address) {
    size_t pos1 = line.find(',');  // Ищем первую запятую
    size_t pos2 = line.find(',', pos1 + 1);  // Ищем вторую запятую
    size_t pos3 = line.find(',', pos2 + 1);  // Ищем третью запятую

    // Проверяем, что все запятые найдены
    if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
        throw runtime_error("Неверный формат адреса: недостаточно разделителей");
    }

    // Заполняем поля структуры Address
    address->Country = line.substr(0, pos1);          // Страна
    address->City = line.substr(pos1 + 1, pos2 - pos1 - 1);    // Город
    address->Street = line.substr(pos2 + 1, pos3 - pos2 - 1);  // Улица
    address->House = line.substr(pos3 + 1);                     // Номер дома
}

//-----------------------------------------------------------------------------
// Функция для приведения адреса к единому формату (верхний регистр)
//-----------------------------------------------------------------------------
void Unify(Address* const address) {
    // Преобразуем все поля к верхнему регистру
    transform(address->Country.begin(), address->Country.end(), address->Country.begin(), ::toupper);
    transform(address->City.begin(), address->City.end(), address->City.begin(), ::toupper);
    transform(address->Street.begin(), address->Street.end(), address->Street.begin(), ::toupper);
    transform(address->House.begin(), address->House.end(), address->House.begin(), ::toupper);
}

//-----------------------------------------------------------------------------
// Функция для форматирования адреса в строку
//-----------------------------------------------------------------------------
string Format(const Address& address) {
    return address.Country + ", " + address.City + ", " + address.Street + ", " + address.House;
}

//-----------------------------------------------------------------------------
// Функция для проверки корректности ввода (пример)
//-----------------------------------------------------------------------------
bool isValidInput(const string& input) {
    // Простая проверка: не должна быть пустой
    return !input.empty();
}
