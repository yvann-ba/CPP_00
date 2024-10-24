#include "utils.hpp"

std::string truncate(std::string message)
{
	if (message.length() > 10)
	{
		message = message.substr(0, 9);
		message += '.';
	}
	return message;
}
