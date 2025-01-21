#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const std::string &csvFile)
{
    std::ifstream file(csvFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open " << csvFile << std::endl;
        return false;
    }

    std::string line;
    if (std::getline(file, line))
    {
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string dateStr;
        std::string rateStr;

        if (std::getline(ss, dateStr, ',') && std::getline(ss, rateStr))
        {
            float rate = static_cast<float>(std::atof(rateStr.c_str()));
            this->_database[dateStr] = rate;
        }
    }
    file.close();
    return true;
}

bool BitcoinExchange::getRateForDate(const std::string &date, float &rate) const
{
    if (!isValidDateFormat(date))
        return false;

    int y, m, d;
    if (!parseDate(date, y, m, d))
        return false;
    std::map<std::string, float>::const_iterator it = this->_database.lower_bound(date);

    if (it == this->_database.begin() && it != this->_database.end() && it->first > date)
        return false;

    if (it == this->_database.end())
    {
        --it;
        rate = it->second;
        return true;
    }

    if (it->first == date)
    {
        rate = it->second;
        return true;
    }

    if (it == this->_database.begin())
        return false;
    --it;
    rate = it->second;
    return true;
}
bool BitcoinExchange::isValidDateFormat(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::parseDate(const std::string &date, int &year, int &month, int &day) const
{
    std::string sYear = date.substr(0, 4);
    std::string sMonth = date.substr(5, 2);
    std::string sDay = date.substr(8, 2);

    year = std::atoi(sYear.c_str());
    month = std::atoi(sMonth.c_str());
    day = std::atoi(sDay.c_str());

    if (!isValidYMD(year, month, day))
        return false;
    return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year < 0)
        return false;
    if ((year % 400) == 0)
        return true;
    if ((year % 100) == 0)
        return false;
    if ((year % 4) == 0)
        return true;
    return false;
}

bool BitcoinExchange::isValidYMD(int year, int month, int day) const
{
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    int maxDays;
    if (month == 2)
    {
        if (isLeapYear(year))
            maxDays = 29;
        else
            maxDays = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else
        maxDays = 31;

    if (day > maxDays)
        return false;

    return true;
}
