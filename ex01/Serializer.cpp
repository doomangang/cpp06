#include "Serializer.hpp"

//OCF

Serializer::Serializer() {
    std::cout << GREEN << "Serializer default constructor called\n" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    *this = other;
    std::cout << GREEN << "Serializer copy constructor called\n" << RESET << std::endl;
}

Serializer::~Serializer() {
    std::cout << RED << "Serializer destructor called\n" << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    std::cout << YELLOW << "Serializer assignment operator called\n" << RESET << std::endl;
    if (this != &other) {
        (void)other;
    }
    return *this;
}

uintptr_t    Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*        Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}