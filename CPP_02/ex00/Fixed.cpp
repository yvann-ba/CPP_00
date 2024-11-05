#include <Fixed.hpp>

Fixed::Fixed(): _fixed_point_number(0) {};

Fixed::Fixed(Fixed& f) {
    _fixed_point_number = f._fixed_point_number;
    _fractional_bits = f._fractional_bits;
    std::cout << "Copy Constructor called" << std::endl;
};

Fixed::~Fixed(){};