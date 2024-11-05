#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed& f);
        ~Fixed();
    private:
        int _fixed_point_number;
        const static int _fractional_bits = 8;
};

#endif