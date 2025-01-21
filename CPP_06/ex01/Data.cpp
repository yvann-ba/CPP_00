#include "Data.hpp"

Data::Data() : id(0), name("")
{
}

Data::Data(const Data &other) : id(other.id), name(other.name)
{
}

Data::~Data()
{
}

Data	&Data::operator=(const Data &other)
{
	if (this != &other) {
        id = other.id;
        name = other.name;
    }
	return (*this);
}