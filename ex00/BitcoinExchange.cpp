#include "BitcoinExchange.hpp"
#include <iostream>     // std::cout, std::cerr
#include <fstream>      // std::ifstream
#include <sstream>      // std::stringstream
#include <cstdlib>      // std::atof
#include <cctype>       // isdigit

// -------------------------------
// Constructors / Destructor
// -------------------------------
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

// -------------------------------
// Public Methods
// -------------------------------

bool BitcoinExchange::loadDatabase(const std::string &csvFile)
{
    std::ifstream file(csvFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open " << csvFile << std::endl;
        return false;
    }

    std::string line;
    // Optionally skip the header line if it says "date,exchange_rate"
    if (std::getline(file, line))
    {
        // If the line is something like "date,exchange_rate", ignore it
        // or re-open the file if you suspect it's data. Let's assume it's a header.
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Split by ','
        std::stringstream ss(line);
        std::string dateStr;
        std::string rateStr;

        if (std::getline(ss, dateStr, ',') && std::getline(ss, rateStr))
        {
            // Trim spaces if needed (not shown, but you can add a trim function)
            float rate = static_cast<float>(std::atof(rateStr.c_str()));
            this->_database[dateStr] = rate;
        }
        // If malformed line, we ignore it silently or handle an error,
        // depending on your preference
    }
    file.close();
    return true;
}

bool BitcoinExchange::getRateForDate(const std::string &date, float &rate) const
{
    // 1) Check if the basic format is correct "YYYY-MM-DD"
    if (!isValidDateFormat(date))
        return false;

    // 2) Parse to integers and check if valid
    int y, m, d;
    if (!parseDate(date, y, m, d))
        return false; // invalid numeric date

    // 3) We do lower_bound. We want the "closest date <= date"
    // Because our key is string "YYYY-MM-DD", and we rely on lexicographical order
    // to match chronological order (which works with zero-padded MM and DD).
    std::map<std::string, float>::const_iterator it = this->_database.lower_bound(date);

    // Cases:
    // a) it == _database.begin() and it->first > date => no earlier date
    if (it == this->_database.begin() && it != this->_database.end() && it->first > date)
        return false;

    // b) if it == _database.end(), everything <= date => pick the last
    if (it == this->_database.end())
    {
        // go back to last element
        --it;
        rate = it->second;
        return true;
    }

    // c) if it->first == date => direct match
    if (it->first == date)
    {
        rate = it->second;
        return true;
    }

    // d) Otherwise, it->first > date => step back
    // but ensure we are not at begin
    if (it == this->_database.begin())
        return false; // can't go back

    --it;
    rate = it->second;
    return true;
}

// -------------------------------
// Private Utility Methods
// -------------------------------

bool BitcoinExchange::isValidDateFormat(const std::string &date) const
{
    // Quick check of form "YYYY-MM-DD", length = 10
    // positions 4,7 must be '-'
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Check digits
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    return true;
}

/*
 * parseDate
 * Extract year, month, day from "YYYY-MM-DD",
 * convert them to int, then validate them with isValidYMD.
 */
bool BitcoinExchange::parseDate(const std::string &date, int &year, int &month, int &day) const
{
    // date is guaranteed to have length 10, "YYYY-MM-DD"
    // Extract substrings
    std::string sYear = date.substr(0, 4);
    std::string sMonth = date.substr(5, 2);
    std::string sDay = date.substr(8, 2);

    // Convert to int
    year = std::atoi(sYear.c_str());
    month = std::atoi(sMonth.c_str());
    day = std::atoi(sDay.c_str());

    // Now validate
    if (!isValidYMD(year, month, day))
        return false;
    return true;
}

/*
 * Check if a given year is leap year:
 *  - divisible by 400 => leap
 *  - else if divisible by 100 => not leap
 *  - else if divisible by 4 => leap
 *  - else => not leap
 */
bool BitcoinExchange::isLeapYear(int year) const
{
    if (year < 0)
        return false; // not handling B.C. years
    if ((year % 400) == 0)
        return true;
    if ((year % 100) == 0)
        return false;
    if ((year % 4) == 0)
        return true;
    return false;
}

/*
 * Check if year, month, day is within valid ranges.
 * year: maybe you accept anything >= 0 or 1970, etc. But let's keep it simple:
 * month: 1-12
 * day: 1-28/29/30/31 depending on month, leap year
 */
bool BitcoinExchange::isValidYMD(int year, int month, int day) const
{
    if (year < 0)
        return false; // or no constraint, as you like
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // days in month
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
