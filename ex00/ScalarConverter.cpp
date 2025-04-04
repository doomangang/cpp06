#include "ScalarConverter.hpp"

std::string    convertToChar(double number);
int convertToInt(double number);
float   convertToFloat(double number);
double  convertToDouble(double number);

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

double  parseNumber(char* number) {
    double  double_num;

    return double_num;
}

void ScalarConverter::convert(char* number)
{
    double  double_num;

    try {
        double_num = parseNumber(number);
    }
    catch (const std::exception& e) {
        std::cout << "char: " << e.what() << std::endl;
        std::cout << "int: " << e.what() << std::endl;
        std::cout << "float: " << e.what() << std::endl;
        std::cout << "double: " << e.what() << std::endl;
        return ;
    }
    try {convertToChar(double_num);} catch (const std::exception& e){std::cout << "char: " << e.what() << std::endl;}
    try {convertToInt(double_num);} catch (const std::exception& e){std::cout << "char: " << e.what() << std::endl;}
    try {convertToFloat(double_num);} catch (const std::exception& e){std::cout << "char: " << e.what() << std::endl;}
    try {convertToDouble(double_num);} catch (const std::exception& e){std::cout << "char: " << e.what() << std::endl;}
}

std::string    convertToChar(double number)
{
    int intNum = static_cast<int>(number);
    if (intNum < 1 || intNum > 128)
        return ("Non displayable");
    return std::string(1, static_cast<char>(intNum));
}

int convertToInt(double number)
{
    //over/underflow
    return atoi(number);
}

float   convertToFloat(double number)
{
    return strtof(number, 0);
}

double  convertToDouble(double number)
{
    return strtod(number, 0);
}
