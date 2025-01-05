#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept> 
#include <algorithm> 
#include <iostream>  

class Span {
private:
    unsigned int _maxSize;         
    std::vector<int> _storage;     

public:
    
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    
    void addNumber(int value);  
    int  shortestSpan() const;  
    int  longestSpan()  const;  

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        while (begin != end) {
            if (_storage.size() >= _maxSize)
                throw std::runtime_error("Span is already full while adding a range");
            _storage.push_back(*begin);
            ++begin;
        }
    }

    
};

#endif
