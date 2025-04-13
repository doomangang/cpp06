
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << GREEN << "ScalarConverter default constructor called\n" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
    std::cout << GREEN << "ScalarConverter copy constructor called\n" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << RED << "ScalarConverter destructor called\n" << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << YELLOW << "ScalarConverter assignment operator called\n" << RESET << std::endl;
    (void)other;
    return *this;
}
