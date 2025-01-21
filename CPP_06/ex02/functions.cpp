#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void)
{
    int randomValue = rand() % 3;

    switch (randomValue)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch (const std::exception& e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B";
		}
		catch (const std::exception& e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "C";
			}
			catch (const std::exception& e) {
				std::cout << "Unknown";
			}
		}
	}
	std::cout << std::endl;
}