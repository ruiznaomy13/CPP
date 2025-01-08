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

	public:
		BitcoinExchange(std::string _file_name);
		~BitcoinExchange();

		std::string getFileName() const;

		void	save_data(const std::string& data_file);
		void	output_info( void );

	private:
		float	compare_date( Date date ) const;
		float	check_input(const std::string& value_str) const;
		void	error_msg(const std::string& msg) const;
		Date	cast_date(std::string& date_str);
		std::map<Date, float>::const_iterator	ft_lower_bound(const Date& date) const;

};

std::string	trim(const std::string& str);

#endif