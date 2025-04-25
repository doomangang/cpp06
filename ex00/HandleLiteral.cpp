#include "ScalarConverter.hpp"

static bool isPrintable(int v) {
    return (v >= 0 && v <= std::numeric_limits<unsigned char>::max())
        && std::isprint(static_cast<unsigned char>(v));
}

void ScalarConverter::handleChar(const std::string& s) {
    char c = (s.size()==3 ? s[1] : s[0]);
    int iv = static_cast<int>(c);
    float fv = static_cast<float>(c);
    double dv = static_cast<double>(c);

    std::cout << "char: '" << c << "'\n"
              << "int: "  << iv << std::endl
              << "float: "  << fv << ".0f\n"
              << "double: " << dv << ".0f\n";
}

void ScalarConverter::handleInt(const std::string& s) {
    errno = 0;
    char* end = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    bool err = (errno == ERANGE) || (*end != '\0')
            || (val < std::numeric_limits<int>::min())
            || (val > std::numeric_limits<int>::max());
    if (err) throw WrongNumberException("int");

    int iv = static_cast<int>(val);
    float fv = static_cast<float>(iv);
    double dv = static_cast<double>(iv);

    // char
    std::cout << "char: ";
    if (!isPrintable(iv))
        std::cout << (iv >= std::numeric_limits<char>::min() && iv <= std::numeric_limits<char>::max()
                         ? "Non displayable" : "impossible");
    else
        std::cout << "'" << static_cast<char>(iv) << "'";
    std::cout << std::endl;

    // int
    std::cout << "int: " << iv << std::endl;

    // float & double
    std::cout << "float: "  << fv << ".0f\n"
              << "double: " << dv << ".0f\n";
}

void ScalarConverter::handleFloat(const std::string& s) {
    errno = 0;
    char* end = 0;
    float f = std::strtof(s.c_str(), &end);
    bool err = (errno == ERANGE) || (*end != 'f' && *end != '\0');
    if (err) throw WrongNumberException("float");

    if (std::isnan(f) || std::isinf(f)) {
        std::cout << "char: impossible\nint: impossible\n";
    } else {
        int iv = static_cast<int>(f);
        std::cout << "char: ";
        if (!isPrintable(iv))
            std::cout << (iv >= std::numeric_limits<char>::min() && iv <= std::numeric_limits<char>::max()
                             ? "Non displayable" : "impossible");
        else
            std::cout << "'" << static_cast<char>(iv) << "'";
        std::cout << std::endl;

        std::cout << "int: ";
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "impossible";
        else
            std::cout << iv;
        std::cout << std::endl;
    }

    std::cout << "float: "  << f << "f" << std::endl
              << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::handleDouble(const std::string& s) {
    errno = 0;
    char* end = 0;
    double d = std::strtod(s.c_str(), &end);
    bool err = (errno == ERANGE) || (*end != '\0');
    if (err) throw WrongNumberException("double");

    if (std::isnan(d) || std::isinf(d)) {
        std::cout << "char: impossible\nint: impossible\n";
    } else {
        int iv = static_cast<int>(d);
        std::cout << "char: ";
        if (!isPrintable(iv))
            std::cout << (iv >= std::numeric_limits<char>::min() && iv <= std::numeric_limits<char>::max()
                             ? "Non displayable" : "impossible");
        else
            std::cout << "'" << static_cast<char>(iv) << "'";
        std::cout << std::endl;

        std::cout << "int: ";
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "impossible";
        else
            std::cout << iv;
        std::cout << std::endl;
    }

    float f = static_cast<float>(d);
    std::cout << "float: "  << f  << "f\n"
              << "double: " << d  << std::endl;
}