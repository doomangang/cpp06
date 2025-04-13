#include "ScalarConverter.hpp"

char        convertToChar(double number);
int         convertToInt(double number);
float       convertToFloat(double number);

const char  *ScalarConverter::NonDisplayableException::what() const throw() { return "Non displayable"; }
const char  *ScalarConverter::ImpossibleException::what() const throw() { return "impossible"; }
const char  *ScalarConverter::NumberFormatException::what() const throw() { return "Wrong Numeric Representation"; }

double  parseNumber(char* number) {
    char *ptr = NULL;
    errno = 0;
    double  double_num = strtod(number, &ptr);
    if (ptr == number || (*ptr != '\0' && *ptr != 'f'))
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

    //char
    try {
        char c = convertToChar(double_num);
        std::cout << "char: " << c << std::endl; 
    } catch (const std::exception& e){std::cerr << "char: " << e.what() << std::endl;}

    //int
    try {
        int i = convertToInt(double_num);
        std::cout << "int: " << i << std::endl; 
    } catch (const std::exception& e){std::cerr << "int: " << e.what() << std::endl;}
    
    //float
    try {
        float f = convertToFloat(double_num);
        std::cout << "float: " 
                    << std::fixed
                    << std::showpoint
                    << f
                    << 'f'
                    << std::endl; 
    } catch (const std::exception& e){std::cerr << "float: " << e.what() << std::endl;}

    //double
    try {
        std::cout << "double: " 
                    << std::fixed
                    << std::showpoint
                    << double_num 
                    << std::endl; 
    } catch (const std::exception& e){std::cerr << "double: " << e.what() << std::endl;}
}

char    convertToChar(double number)
{
    int intNum = static_cast<int>(number);
    if (std::isnan(number) || std::isinf(number))
        throw ScalarConverter::ImpossibleException();
    if (intNum < 1 || intNum > 128)
        throw ScalarConverter::NonDisplayableException();
    return static_cast<char>(intNum);
}

int convertToInt(double number)
{
    if (std::isnan(number) || std::isinf(number))
        throw ScalarConverter::ImpossibleException();
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
