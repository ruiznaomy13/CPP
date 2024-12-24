#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib> 

struct Date {
    int year, month, day;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

class BitcoinExchange {
private:
    std::string file_name;
    std::map<Date, float> Data;

    void save_data(std::string data_file);
    void error_msg(std::string msg);
    Date cast_date(const std::string& date_str);

public:
    BitcoinExchange(std::string file_name);
    ~BitcoinExchange();

    std::string getFileName();
    void show_data() const;
};

#endif
