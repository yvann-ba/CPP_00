#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

    bool        isValidDateFormat(const std::string &date) const;
    bool        parseDate(const std::string &date, int &year, int &month, int &day) const;
    bool        isLeapYear(int year) const;
    bool        isValidYMD(int year, int month, int day) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool        loadDatabase(const std::string &csvFile);

    bool        getRateForDate(const std::string &date, float &rate) const;
};

#endif
