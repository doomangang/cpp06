#include "ScalarConverter.hpp"

void ScalarConverter::convert(char* number)
{
    LiteralType type = detectType(number);

    switch (type)
    {
        case LT_CHAR:
            handleChar(number);
            break;
        case LT_INT:
            handleInt(number);
            break;
        case LT_FLOAT:
            handleFloat(number);
            break;
        case LT_DOUBLE:
            handleDouble(number);
            break;
        default:
            std::cout << "Error: invalid literal format" << std::endl;
            break;
    }
}

LiteralType  detectType(std::string number) {

    //char
    if (number.length() == 1 && !isdigit(number[0]))
        return LT_CHAR;
    if (number.length() == 3 && number[0] == '\'' && number[2] == '\'' && !isdigit(number[1]))
        return LT_CHAR;

    //pseudo-literal
    if (number == "nan" || number == "+inf" || number == "-inf")
        return LT_DOUBLE;
    if (number == "nanf" || number == "+inff" || number == "-inff")
        return LT_FLOAT;
    
    bool    hasDot = (number.find('.') != std::string::npos);
    bool    endsF = (!number.empty() && number[number.length() - 1] == 'f');

    if (hasDot) {
        if (endsF) return LT_FLOAT;
        return LT_DOUBLE;
    }

    size_t i = 0;
    if (!number.empty() && (number[0] == '+' || number[0] == '-'))
        i++;
    for (; i < number.length(); i++) {
        if (!isdigit(number[i]))
            return LT_INVALID;
    }
    return LT_INT;
}
