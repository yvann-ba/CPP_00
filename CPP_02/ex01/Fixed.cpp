#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _rawBits(integer << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _rawBits(static_cast<int32_t>(number * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other) 
        this->_rawBits = other._rawBits;
    return *this;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

int Fixed::toInt() const {
    return _rawBits >> _fractionalBits;
}

float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}