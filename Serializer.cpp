#include "Serializer.hpp"
#include "Convert.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}