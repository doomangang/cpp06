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

    if (iss.fail()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
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
    
    if (endPtr == input.c_str() || *endPtr != '\0')
        return false;
    
    if (errno == ERANGE)
        return false;
    
    if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        return false;
    
    result = static_cast<int>(l);
    return true;
}
