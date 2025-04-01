#include "ScalarConverter.hpp"

std::string    convertToChar(char* number);
int convertToInt(char* number);
float   convertToFloat(char* number);
double  convertToDouble(char* number);

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
    if (this != &other) {
        // assignment code here
    }
    return *this;
}

void ScalarConverter::convert(char* number)
{
    std::cout << "char: " << convertToChar(number) << std::endl;
    std::cout << "int: " << convertToInt(number) << std::endl;
    std::cout << "float: " << convertToFloat(number) << std::endl;
    std::cout << "double: " << convertToDouble(number) << std::endl;
}

std::string    convertToChar(char* number)
{
    int intNum = atoi(number);
    if (intNum < 1 || intNum > 128)
        return ("Non displayable");
    return std::string(1, static_cast<char>(intNum));
}

int convertToInt(char* number)
{
    //over/underflow
    return atoi(number);
}

float   convertToFloat(char* number)
{
    return strtof(number, 0);
}

double  convertToDouble(char* number)
{
    return strtod(number, 0);
}
