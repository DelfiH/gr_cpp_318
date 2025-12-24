#ifndef TASK8_H
#define TASK8_H

#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void task8();
void Parse(const std::string& line, Address* const address);
void Unify(Address* const address);
std::string Format(const Address& address);

#endif
