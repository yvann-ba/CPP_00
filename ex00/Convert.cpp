#include "Convert.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>    
#include <limits>   

Convert::Convert(const std::string &literal) : _literal(literal), _value(0.0)
{
}

Convert::Convert(const Convert &other) : _literal(other._literal), _value(other._value)
{
}

Convert &Convert::operator=(const Convert &other)
{
    if (this != &other)
    {
        this->_literal = other._literal;
        this->_value   = other._value;
    }
    return *this;
}

Convert::~Convert()
{
}

void Convert::handleInput()
{
    bool isChar  = this->isCharLiteral();
    bool isInt   = this->isIntLiteral();
    bool isFloat = this->isFloatLiteral();
    bool isDbl   = this->isDoubleLiteral();

    if (!isChar && !isInt && !isFloat && !isDbl)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (isChar)
    {
        char c = this->_literal[1];
        this->_value = static_cast<double>(c);
    }
    else if (isFloat)
    {
        if (this->isPseudoFloat())
        {
            if (this->_literal == "nanf")
                this->_value = std::numeric_limits<double>::quiet_NaN();
            else if (this->_literal == "+inff" || this->_literal == "inff")
                this->_value = std::numeric_limits<double>::infinity();
            else if (this->_literal == "-inff")
                this->_value = -std::numeric_limits<double>::infinity();
        }
        else
        {
            std::string tmp = this->_literal.substr(0, this->_literal.size() - 1);
            char *endPtr = NULL;
            this->_value = std::strtod(tmp.c_str(), &endPtr);
        }
    }
    else if (isDbl)
    {
        if (this->isPseudoDouble())
        {
            if (this->_literal == "nan")
                this->_value = std::numeric_limits<double>::quiet_NaN();
            else if (this->_literal == "+inf" || this->_literal == "inf")
                this->_value = std::numeric_limits<double>::infinity();
            else if (this->_literal == "-inf")
                this->_value = -std::numeric_limits<double>::infinity();
        }
        else
        {
            char *endPtr = NULL;
            this->_value = std::strtod(this->_literal.c_str(), &endPtr);
        }
    }
    else
    {
        char *endPtr = NULL;
        long lvalue = std::strtol(this->_literal.c_str(), &endPtr, 10);
        this->_value = static_cast<double>(lvalue);
    }

    printChar();
    printInt();
    printFloat();
    printDouble();
}

bool Convert::isCharLiteral() const
{
    if (this->_literal.size() == 3 && this->_literal[0] == '\'' && this->_literal[2] == '\'')
        return true;
    return false;
}

bool Convert::isIntLiteral() const
{
    std::string s = this->_literal;
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-')
        i++;
    for (; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

bool Convert::isFloatLiteral() const
{
    if (this->isPseudoFloat())
        return true;

    if (this->_literal.size() < 2)
        return false;
    if (this->_literal[this->_literal.size() - 1] != 'f')
        return false;

    std::string tmp = this->_literal.substr(0, this->_literal.size() - 1);
    char *endPtr = NULL;
    std::strtod(tmp.c_str(), &endPtr);
    if (*endPtr != '\0')
        return false;
    return true;
}

bool Convert::isDoubleLiteral() const
{
    if (this->isPseudoDouble())
        return true;

    char *endPtr = NULL;
    std::strtod(this->_literal.c_str(), &endPtr);
    if (*endPtr != '\0')
        return false;
    return true;
}

bool Convert::isPseudoFloat() const
{
    if (this->_literal == "nanf" || 
        this->_literal == "+inff" ||
        this->_literal == "-inff" ||
        this->_literal == "inff")
        return true;
    return false;
}

bool Convert::isPseudoDouble() const
{
    if (this->_literal == "nan"  ||
        this->_literal == "+inf" ||
        this->_literal == "-inf" ||
        this->_literal == "inf")
        return true;
    return false;
}


void Convert::printChar() const
{
    std::cout << "char: ";
    if (std::isnan(this->_value) || std::isinf(this->_value) ||
        this->_value < 0.0 || this->_value > 127.0)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(this->_value);
    if (c < 32 || c > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

void Convert::printInt() const
{
    std::cout << "int: ";
    if (std::isnan(this->_value) || std::isinf(this->_value) ||
        this->_value < static_cast<double>(std::numeric_limits<int>::min()) ||
        this->_value > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(this->_value);
    std::cout << i << std::endl;
}

void Convert::printFloat() const
{
    std::cout << "float: ";
    if (std::isnan(this->_value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(this->_value))
    {
        if (this->_value < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
    }
    else
    {
        float f = static_cast<float>(this->_value);
        std::cout << f << "f" << std::endl;
    }
}

void Convert::printDouble() const
{
    std::cout << "double: ";
    if (std::isnan(this->_value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(this->_value))
    {
        if (this->_value < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "+inf" << std::endl;
    }
    else
    {
        std::cout << this->_value << std::endl;
    }
}
