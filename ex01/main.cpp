#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main() {
    Data d;
    d.id = 42;
    d.value = "jihyjeon";

    Data* p1 = &d;

    uintptr_t   raw = Serializer::serialize(p1);
    Data*       p2 = Serializer::deserialize(raw);

    std::cout << GREEN << std::boolalpha << (p1 == p2) << RESET << std::endl;

    return 0;
}