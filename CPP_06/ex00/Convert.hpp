#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
public:
    Convert(const std::string &literal);
    Convert(const Convert &other);
    Convert &operator=(const Convert &other);
    ~Convert();

    void handleInput();

private:
    std::string _literal;
    
    double      _value;
    

    bool isCharLiteral() const;
    bool isIntLiteral() const;
    bool isFloatLiteral() const;
    bool isDoubleLiteral() const;

    bool isPseudoFloat() const;
    bool isPseudoDouble() const;

    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;
};

#endif
