#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // for atof

static void trim(std::string &s)
{
    // Remove leading whitespace
    while (!s.empty() && (s[0] == ' ' || s[0] == '\t'))
        s.erase(s.begin());

    // Remove trailing whitespace
    while (!s.empty() && (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t'))
        s.erase(s.size() - 1, 1);
}

int main(int argc, char **argv)
{
    // 1) Check for correct usage
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // 2) Create a BitcoinExchange instance & load the CSV database
    BitcoinExchange btc;
    if (!btc.loadDatabase("cpp_09/data.csv"))
    {
        // If the data.csv file can't be loaded, we stop.
        return 1;
    }

    // 3) Open the user-provided file (e.g. input.txt)
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Attempt to read the first line (maybe "date | value"), skip it
    {
        std::string header;
        if (std::getline(inputFile, header))
        {
            // If it is "date | value", we just ignore it
            // Otherwise, it's data or something, but let's assume we skip anyway
        }
    }

    // 4) Read each subsequent line
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string dateStr;
        std::string valueStr;

        // We split on '|'
        if (!std::getline(ss, dateStr, '|'))
        {
            // If there's no '|', then invalid input
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim whitespace
        trim(dateStr);
        trim(valueStr);

        // Convert value to float
        float amount = static_cast<float>(std::atof(valueStr.c_str()));

        // Check if negative
        if (amount < 0.0f)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        // Check if greater than 1000
        if (amount > 1000.0f)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // 5) Query the exchange rate
        float rate = 0.0f;
        if (!btc.getRateForDate(dateStr, rate))
        {
            // This includes invalid date or no earlier date in DB
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }

        // 6) Print result: "YYYY-MM-DD => amount = computed_value"
        float result = rate * amount;
        std::cout << dateStr << " => " << amount << " = " << result << std::endl;
    }

    inputFile.close();
    return 0;
}
