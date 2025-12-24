#include "address.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

//-----------------------------------------------------------------------------
// Функция для удаления пробелов в начале и конце строки
//-----------------------------------------------------------------------------
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

//-----------------------------------------------------------------------------
// Функция для разбора строки адреса
//-----------------------------------------------------------------------------
void Parse(const std::string& line, Address* const address) {
    std::stringstream ss(line);
    address->Country = "";
    address->City = "";
    address->Street = "";
    address->House = "";
    std::string token;
    std::getline(ss, address->Country, ',');
    std::getline(ss, address->City, ',');
    std::getline(ss, address->Street, ',');
    std::getline(ss, token, ',');
    address->House = token;

    address->Country = trim(address->Country);
    address->City = trim(address->City);
    address->Street = trim(address->Street);
    address->House = trim(address->House);

    if (address->Country.empty() || address->City.empty() || address->Street.empty() || address->House.empty()) {
        throw std::runtime_error("Неполный адрес ??");
    }
}

//-----------------------------------------------------------------------------
// Функция для приведения всех символов адреса к верхнему регистру
//-----------------------------------------------------------------------------
void Unify(Address* const address) {
  std::transform(address->Country.begin(), address->Country.end(), address->Country.begin(), ::toupper);
  std::transform(address->City.begin(), address->City.end(), address->City.begin(), ::toupper);
  std::transform(address->Street.begin(), address->Street.end(), address->Street.begin(), ::toupper);
  std::transform(address->House.begin(), address->House.end(), address->House.begin(), ::toupper);
}

//-----------------------------------------------------------------------------
// Функция для форматирования адреса в строку
//-----------------------------------------------------------------------------
std::string Format(const Address& address) {
   return address.Country + ", " + address.City + ", " + address.Street + ", " + address.House;
}

//-----------------------------------------------------------------------------
// Главная функция (пример использования)
//-----------------------------------------------------------------------------
void runAddressTask() {
    std::cout << "Введите адрес в формате: Страна, Город, Улица, Дом" << std::endl;
    std::cout << "Например:" << std::endl;
    std::cout << "Россия, Москва, Тверская, 15" << std::endl;
    std::cout << "USA, New York, 5th Avenue, 10" << std::endl;
    std::cout << "Germany, Berlin, Unter den Linden, 77" << std::endl;

    std::string inputLine;
    std::getline(std::cin, inputLine);

    Address address;
    try {
        Parse(inputLine, &address);
        Unify(&address);
        std::cout << "Введенный адрес: " << Format(address) << std::endl;
    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
    }
}
