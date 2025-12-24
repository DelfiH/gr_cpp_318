#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

//-----------------------------------------------------------------------------
// Структура для хранения информации об адресе
//-----------------------------------------------------------------------------
struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void Parse(const std::string& line, Address* const address);
void Unify(Address* const address);
std::string Format(const Address& address);

#endif
