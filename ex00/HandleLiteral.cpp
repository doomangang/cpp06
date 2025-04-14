#include "ScalarConverter.hpp"


void    handleChar(std::string number) {
    char    c = number[0];
    if (number.length() == 3 && number[0] == '\'' && number[2] == '\'')
        c = number[1];
    else
        c = number[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " 
              << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " 
              << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void    handleInt(std::string number) {
    errno = 0;
    int i = std::atoi(number.c_str());

    char c = static_cast<char>(i);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " 
              << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " 
              << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void    handleFloat(std::string number) {
    float f = static_cast<float>(atof(number.c_str()));
    char c = static_cast<char>(f);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " 
              << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " 
              << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void    handleDouble(std::string number){
    double d = atof(number.c_str());
    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " 
              << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " 
              << std::fixed << std::setprecision(1) << d << std::endl;
}

bool convertToInt(std::string input, int &result)
{
    errno = 0;
    char *endPtr = 0;
    long l = std::strtol(input.c_str(), &endPtr, 10);
    
    // Check if no conversion was done.
    if (endPtr == input.c_str() || *endPtr != '\0')
        return false;
    
    // Check errno for overflow/underflow.
    if (errno == ERANGE)
        return false;
    
    // Verify that the long fits in an int.
    if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        return false;
    
    result = static_cast<int>(l);
    return true;
}
//prob 1. number with several fs. 