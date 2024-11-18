#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _rawBits(integer << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(number * (1 << this->_fractionalBits));
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

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
    os << fp.toFloat();
    return os;
}


bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits >other._rawBits;
}
bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}
bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._rawBits = this->_rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._rawBits = this->_rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long temp = static_cast<long>(this->_rawBits) * static_cast<long>(other._rawBits);
    result._rawBits = static_cast<int>(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long temp = (static_cast<long>(this->_rawBits) << _fractionalBits) / other._rawBits;
    result._rawBits = static_cast<int>(temp);
    return result;
}


Fixed& Fixed::operator++() {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_rawBits;
    return temp;
}

Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_rawBits;
    return temp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return f1;
    else
        return f2;
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 < f2)
        return f1;
    else
        return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 > f2)
        return f1;
    else
        return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 > f2)
        return f1;
    else
        return f2;
}