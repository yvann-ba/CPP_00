#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
static void trim(std::string &s)
{
    while (!s.empty() && (s[0] == ' ' || s[0] == '\t'))
        s.erase(s.begin());

    while (!s.empty() && (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t'))
        s.erase(s.size() - 1, 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase("cpp_09/data.csv"))
    {
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    {
        std::string header;
        if (std::getline(inputFile, header))
        {
        }
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string dateStr;
        std::string valueStr;

        if (!std::getline(ss, dateStr, '|'))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        trim(dateStr);
        trim(valueStr);

        float amount = static_cast<float>(std::atof(valueStr.c_str()));

        if (amount < 0.0f)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (amount > 1000.0f)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = 0.0f;
        if (!btc.getRateForDate(dateStr, rate))
        {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }

        float result = rate * amount;
        std::cout << dateStr << " => " << amount << " = " << result << std::endl;
    }

    inputFile.close();
    return 0;
}
