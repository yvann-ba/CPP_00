#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other)
    : _maxSize(other._maxSize), _storage(other._storage) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_maxSize = other._maxSize;
        this->_storage = other._storage; 
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_storage.size() >= _maxSize) {
        throw std::runtime_error("Span is already full");
    }
    _storage.push_back(value);
}

int Span::shortestSpan() const {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements to compute shortest Span");
    
    std::vector<int> copy = _storage;
    std::sort(copy.begin(), copy.end());

    int minSpan = copy[1] - copy[0]; 

    for (size_t i = 0; i < copy.size() - 1; i++) {
        int diff = copy[i+1] - copy[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements to compute longestSpan");
    
    int minVal = *std::min_element(_storage.begin(), _storage.end());
    int maxVal = *std::max_element(_storage.begin(), _storage.end());
    return maxVal - minVal;
}

