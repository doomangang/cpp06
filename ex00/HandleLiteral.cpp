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
    
    int i = 0;
    std::istringstream  iss(number);
    iss >> i;

    if (iss.fail())
        throw ScalarConverter::WrongNumberException("INT");
    else {
        std::cout << "char: ";
        if (std::isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "Impossible" << std::endl;
        
        //int
        std::cout << "int: " << i << std::endl;
    }
    
    float f = float(0);
    std::istringstream issF(number);
    issF >> f;
    std::cout << "float: " ;
    if (issF.fail())
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    double d = double(0);
    std::istringstream issD(number);
    issD >> d;
    std::cout << "double: ";
    if (issD.fail())
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void    handleFloat(std::string number) {
    char* end = 0;
    float f = strtof(number.c_str(), &end);
    bool rangeErr = (errno == ERANGE);
    if (rangeErr)
        throw ScalarConverter::WrongNumberException("FLOAT");

    char c = static_cast<char>(f);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;


    std::cout << "float: " 
            << std::fixed << f << "f" << std::endl;
    std::cout << "double: " 
            << std::fixed << static_cast<double>(f) << std::endl;
}

void    handleDouble(std::string number){
    char* end = 0;
    double d = strtod(number.c_str(), &end);
    bool rangeErr = (errno == ERANGE);
    if (rangeErr)
        throw ScalarConverter::WrongNumberException("DOUBLE");

    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    std::cout << "float: " 
            << std::fixed << static_cast<float>(d) << "f" << std::endl;
    
    std::cout << "double: " 
            << std::fixed << d << std::endl;
}
