#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    {
        
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; 
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;  
    }

    {
        Span bigSpan = Span(10000);

        std::vector<int> v;
        for (int i = 0; i < 10000; ++i) {
            v.push_back(i * 2); 
        }
        try {
            bigSpan.addRange(v.begin(), v.end());
            std::cout << "Shortest span: "
                      << bigSpan.shortestSpan() << std::endl;
            std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    {   
        Span sp2 = Span(3);
        sp2.addNumber(42);
        try {
            std::cout << sp2.shortestSpan() << std::endl; 
        } catch (std::exception &e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }
    }
    {
        Span sp3 = Span(2);
        try {
            sp3.addNumber(100);
            sp3.addNumber(101);
            sp3.addNumber(102); 
        } catch (std::exception &e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }
    }

    return 0;
}
