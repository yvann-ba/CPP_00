#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(42);
    std::cout << "Top: " << mstack.top() << std::endl; 

    mstack.pop();
    std::cout << "Top: " << mstack.top() << std::endl;    
    std::cout << "Size: " << mstack.size() << std::endl;    

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "Top : " << mstack.top() << std::endl;      
    std::cout << "Size: " << mstack.size() << std::endl;   
    
    MutantStack<int> copy(mstack);
    std::cout << "Copy size: " << copy.size() << std::endl;

    return 0;
}
