#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        try {
            std::vector<int>::iterator it = easyfind(vec, 2);
            std::cout << "Found: " << *it << std::endl; 
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        try {
            std::list<int>::iterator it = easyfind(lst, 25);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl; 
        }
    }

    return 0;
}
