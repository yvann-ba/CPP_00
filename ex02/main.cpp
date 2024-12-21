#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Base* basePtr = generate();

        std::cout << "identify(*p): ";
        identify(basePtr);

        std::cout << "identify(&p): ";
        identify(*basePtr);

        delete basePtr;

        std::cout << "-----------------" << std::endl;
    }

    return 0;
}
