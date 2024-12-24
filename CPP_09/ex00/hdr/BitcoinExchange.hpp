#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

struct Date {
    int year;
    int month;
    int day;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

class BitcoinExchange {
public:
    BitcoinExchange(std::string _file_name);
    ~BitcoinExchange();
    std::string getFileName() const;
    void save_data(const std::string& data_file);
    void show_data() const;

private:
    std::string file_name;
    std::map<Date, float> Data;

    Date cast_date(const std::string& date_str);
    void error_msg(const std::string& msg) const;
};

#endif