#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float number);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;

        friend std::ostream& operator<<(std::ostream& os, const Fixed& fp);
    private:
        int _rawBits;
        const static int _fractionalBits = 8;
};

#endif