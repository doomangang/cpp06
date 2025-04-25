#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#include "Data.hpp"

#define uintptr_t unsigned long

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

class Serializer {
private:
    /* member attributes */
    /* Orthodox Canonical Form (OCF) */
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);
public:
    /* getter & setter */

    /* additional methods */
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
    /* exception classes */
};

/* operators */
#endif