#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

struct Date
{
	int	year;
	int	month;
	int	day;

	bool operator<(const Date& other) const
	{
		if (year != other.year) return year < other.year;
		if (month != other.month) return month < other.month;
		return day < other.day;
	}
};

class BitcoinExchange
{
	private:
		std::string				file_name;
		std::map<Date, float>	Data;

		Date cast_date(std::string& date_str);
		void error_msg(const std::string& msg) const;

	public:
		BitcoinExchange(std::string _file_name);
		~BitcoinExchange();
		std::string getFileName() const;
		void	save_data(const std::string& data_file);
		float	compare_date( Date date ) const;
		void	output_info( void );

		void show_data() const; //QUITAR
};

#endif