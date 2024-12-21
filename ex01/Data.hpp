#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
public:
    int         id;
    std::string name;
    Data();
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data();
};

#endif
