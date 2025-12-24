#include "address.h"
#include <iostream>
#include <sstream>
#include <vector>

void Parse(const std::string& line, Address* address) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> parts;

    while (std::getline(ss, token, ',')) {
        parts.push_back(token);
    }

    if (parts.size() != 5) { // Ожидаем 5 частей: Страна, Город, Улица, Дом, Квартира
        throw std::runtime_error("Неверный формат адреса");
    }

    address->city = parts[1]; // Город (вторая часть)
    address->street = parts[2]; // Улица (третья часть)

    // Попытка извлечь номер дома и квартиры (очень упрощенно)
    std::stringstream house_ss(parts[3]);
    std::string house_token;
    std::vector<std::string> house_parts;

    while (std::getline(house_ss, house_token, ' ')) {
        house_parts.push_back(house_token);
    }

    if (house_parts.size() >= 2) {
        try {
            address->building = std::stoi(house_parts[1]); // Предполагаем, что номер дома идет после "д."
        } catch (const std::invalid_argument& e) {
            address->building = 0; // Или другое значение по умолчанию
        }
    }

    std::stringstream apartment_ss(parts[4]);
    std::string apartment_token;
    std::vector<std::string> apartment_parts;

    while (std::getline(apartment_ss, apartment_token, ' ')) {
        apartment_parts.push_back(apartment_token);
    }

     if (apartment_parts.size() >= 2) {
        try {
            address->apartment = std::stoi(apartment_parts[1]); // Предполагаем, что номер квартиры идет после "кв."
        } catch (const std::invalid_argument& e) {
            address->apartment = 0; // Или другое значение по умолчанию
        }
    }

}
