#include "iter.hpp"
#include <iostream>

template<typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

void addOne(int & x) {
    x += 1;
}

void makeUpperCase(char & c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(intArr, 5, printElement<int>);
    std::cout << std::endl;
    
    iter(intArr, 5, addOne);
    std::cout << "After adding 1: ";
    iter(intArr, 5, printElement<int>);
    std::cout << std::endl;

    char charArr[] = "Hello";
    std::cout << "Original string: " << charArr << std::endl;
    iter(charArr, 5, makeUpperCase);
    std::cout << "Uppercase: " << charArr << std::endl;

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Double array: ";
    iter(doubleArr, 5, printElement<double>);
    std::cout << std::endl;

    return 0;
}