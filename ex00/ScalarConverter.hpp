#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>

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

class ScalarConverter {
private:
    /* member attributes */

    /* Orthodox Canonical Form (OCF) */
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    
public:
    /* getter & setter */

    /* additional methods */
    static void convert(char* number);

    /* exception classes */
    class NonDisplayableException : public std::exception {
        public:
            const char *what() const throw();
    };

    class ImpossibleException : public std::exception {
        public:
            const char *what() const throw();
    };

    class NumberFormatException : public std::exception {
        public:
            const char *what() const throw();
    };
};

/* operators */
#endif