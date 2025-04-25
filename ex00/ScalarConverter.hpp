#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

/* Color Sets */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;250m"

enum LiteralType {
    LT_CHAR,
    LT_INT,
    LT_FLOAT,
    LT_DOUBLE,
    LT_INVALID
};

class ScalarConverter {
private:
    /* member attributes */

    /* Orthodox Canonical Form (OCF) */
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);

    static LiteralType detectType(const std::string& s);

    static void handleChar(const std::string& s);
    static void handleInt(const std::string& s);
    static void handleFloat(const std::string& s);
    static void handleDouble(const std::string& s);
    
public:
    /* getter & setter */

    /* additional methods */
    static void convert(const std::string& input);

    /* exception classes */
    class WrongNumberException : public std::exception {
        std::string _msg;
        public:
            explicit WrongNumberException(const std::string& type);
            virtual ~WrongNumberException() throw();
            const char *what() const throw();
    };
};


#endif