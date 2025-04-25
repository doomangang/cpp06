#include "ScalarConverter.hpp"

//exception

ScalarConverter::WrongNumberException::WrongNumberException(const std::string& type) 
: _msg("Conversion error: invalid input for type \"" + type + "\"") {}

const char *ScalarConverter::WrongNumberException::what() const throw() {
	return _msg.c_str();
}

ScalarConverter::WrongNumberException::~WrongNumberException() throw() {}

void ScalarConverter::convert(const std::string& input) {
    LiteralType t = detectType(input);
    try {
        switch (t) {
            case LT_CHAR:   handleChar(input);    break;
            case LT_INT:    handleInt(input);     break;
            case LT_FLOAT:  handleFloat(input);   break;
            case LT_DOUBLE: handleDouble(input);  break;
            default:
                throw WrongNumberException("unknown");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

LiteralType ScalarConverter::detectType(const std::string& s) {
    if (s.empty()) return LT_INVALID;

    // Char literal: single non-digit or quoted char
    if (s.size() == 1 && !std::isdigit(s[0]))
        return LT_CHAR;
    if (s.size() == 3 && s[0]=='\'' && s[2]=='\'' && !std::isdigit(s[1]))
        return LT_CHAR;

    // Pseudo-literals
    if (s == "nanf" || s == "+inff" || s == "-inff") return LT_FLOAT;
    if (s == "nan"  || s == "+inf"  || s == "-inf")  return LT_DOUBLE;

    bool endsWithF = (s.size() > 0 && s[s.size()-1] == 'f');
    bool hasDot    = (s.find('.') != std::string::npos);

    size_t i = 0;
    if (s[0]=='+' || s[0]=='-') ++i;
    for (; i < s.size(); ++i) {
        if (std::isdigit(s[i])) continue;
        if (hasDot && s[i]=='.') continue;
        if (endsWithF && i==s.size()-1 && s[i]=='f') continue;
        return LT_INVALID;
    }

    if (hasDot && endsWithF) return LT_FLOAT;
    if (hasDot)             return LT_DOUBLE;
    if (endsWithF)          return LT_INVALID;
    return LT_INT;
}
