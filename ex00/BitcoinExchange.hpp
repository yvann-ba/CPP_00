#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
    // A map from date string "YYYY-MM-DD" to float exchange rate
    std::map<std::string, float> _database;

    // Private utility functions
    bool        isValidDateFormat(const std::string &date) const;
    bool        parseDate(const std::string &date, int &year, int &month, int &day) const;
    bool        isLeapYear(int year) const;
    bool        isValidYMD(int year, int month, int day) const;

public:
    // Constructors / Destructors
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // Load CSV data into _database
    bool        loadDatabase(const std::string &csvFile);

    // Given a date as string, get the exchange rate (or the closest lower date).
    // Returns true if found a valid date, false otherwise.
    bool        getRateForDate(const std::string &date, float &rate) const;
};

#endif
