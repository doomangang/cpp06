#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    int r = std::rand() % 3;
    if (r == 0) return new A;
    if (r == 1) return new B;
    return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout<<"A\n"; return; } catch(...) {}
    try { (void)dynamic_cast<B&>(p); std::cout<<"B\n"; return; } catch(...) {}
    try { (void)dynamic_cast<C&>(p); std::cout<<"C\n"; return; } catch(...) {}
}

int main() {
    // seed once
    std::srand(static_cast<unsigned>(std::time(NULL)));

    const int TEST_COUNT = 10;
    for (int i = 0; i < TEST_COUNT; ++i) {
        Base* obj = generate();

        std::cout << "--- Test #" << (i + 1) << " ---\n";

        // identify by pointer
        std::cout << "identify(Base*): " << GREEN;
        identify(obj);

        // identify by reference
        std::cout << RESET << "identify(Base&): " << CYAN;
        identify(*obj);

        std::cout << RESET << std::endl;

        delete obj;
    }

    return 0;
}