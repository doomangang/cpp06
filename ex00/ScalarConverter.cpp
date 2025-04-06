#include "ScalarConverter.hpp"

std::string convertToChar(double number);
int         convertToInt(double number);
float       convertToFloat(double number);

const char  *ScalarConverter::NonDisplayableException::what() const throw() { return "Non displayable"; }
const char  *ScalarConverter::ImpossibleException::what() const throw() { return "impossible"; }
const char  *ScalarConverter::NumberFormatException::what() const throw() { return "Wrong Numeric Representation"; }

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
    char *ptr = NULL;
    errno = 0;
    double  double_num = strtod(number, &ptr);
    if (ptr == number || *ptr != '\0')
        throw ScalarConverter::ImpossibleException();
    if (errno == ERANGE) 
        throw ScalarConverter::ImpossibleException();
    return double_num;
}

void ScalarConverter::convert(char* number)
{
    double  double_num;

    try { double_num = parseNumber(number); }
    catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return ;
    }
    try {std::cout << "char: " << convertToChar(double_num) << std::endl; } catch (const std::exception& e){std::cerr << "char: " << e.what() << std::endl;}
    try {convertToInt(double_num);} catch (const std::exception& e){std::cerr << "char: " << e.what() << std::endl;}
    try {convertToFloat(double_num);} catch (const std::exception& e){std::cerr << "char: " << e.what() << std::endl;}
    try {std::cout << "double: " << double_num << std::endl; } catch (const std::exception& e){std::cerr << "char: " << e.what() << std::endl;}
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
    //over/underflow handling
    if (number > static_cast<double>(std::numeric_limits<int>::max()))
        throw ScalarConverter::ImpossibleException();
    if (number < static_cast<double>(std::numeric_limits<int>::min()))
        throw ScalarConverter::ImpossibleException();
    return static_cast<int>(number);
}

float  convertToFloat(double number)
{
    if (number > static_cast<double>(std::numeric_limits<float>::max()))
        throw ScalarConverter::ImpossibleException();
    if (number < -static_cast<double>(std::numeric_limits<float>::max()))
        throw ScalarConverter::ImpossibleException();
    return static_cast<float>(number);
}
