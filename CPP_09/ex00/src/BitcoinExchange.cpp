/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:29:26 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/08 19:29:03 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string _file_name)
{
	this->file_name = _file_name;
	save_data("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->file_name = other.file_name;
	this->Data = other.Data;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->file_name = other.file_name;
		this->Data = other.Data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::getFileName() const {	return (file_name); }

void	BitcoinExchange::save_data(const std::string& data_file)
{
	std::ifstream	file(data_file.c_str());
	std::string		line;
	float			value;
	Date			date;

	if (!file)
	{
		error_msg("ERROR: Cannot open file");
		return ;
	}

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date_str, value_str;

		if (!std::getline(ss, date_str, ',') || !std::getline(ss, value_str))
			continue ;

		try {
			date = cast_date(date_str);
		} catch (const std::exception& e) {	}

		if (date.year == 0 && date.month == 0 && date.day == 0)
			continue ;

		value = std::atof(value_str.c_str());
		Data[date] = value;
	}
}

Date	BitcoinExchange::cast_date(std::string& date_str)
{
	int year = 0, month = 0, day = 0;
	date_str = trim(date_str);

	if (sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		throw std::runtime_error("Error: invalid date format.");
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw std::runtime_error("Error: Invalid date format. Expected YYYY-MM-DD.");

	return (Date){year, month, day};
}

float	BitcoinExchange::check_input(const std::string& value_str) const
{
	double	value = std::atof(value_str.c_str());
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 2147483647)
		throw std::runtime_error("Error: too large a number.");
	return static_cast<float>(value);
}

void	BitcoinExchange::error_msg(const std::string& msg) const
{
	std::cerr << msg << std::endl;
}

std::map<Date, float>::const_iterator BitcoinExchange::ft_lower_bound(const Date& date) const
{
	std::map<Date, float>::const_iterator it = Data.begin();
	std::map<Date, float>::const_iterator best_match = Data.end();

	while (it != Data.end())
	{
		if (!(it->first < date))
		{
			if (!(date < it->first))
				return (it);
			break ;
		}
		best_match = it;
		++it;
	}

	return (best_match);
}


float	BitcoinExchange::compare_date(Date date) const
{
	std::map<Date, float>::const_iterator	it = ft_lower_bound(date);

	if (it == Data.end())
		throw std::runtime_error("Error: No valid date found.");
	return (it->second);
}

void BitcoinExchange::output_info(void)
{
	std::ifstream file(file_name.c_str());
	std::string line;

	if (!file)
	{
		error_msg("Error: Cannot open file " + file_name);
		return ;
	}

	if (!std::getline(file, line)) {
		error_msg("Error: File is empty or malformed.");
		return ;
	}

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date_str, value_str;

		if (!std::getline(ss, date_str, '|') || !std::getline(ss, value_str))
		{
			error_msg("Error: bad input => " + line);
			continue;
		}

		date_str = trim(date_str);
		value_str = trim(value_str);

		try
		{
			Date	date = cast_date(date_str);
			float	value = check_input(value_str);
			std::cout << date_str << " => " << value
					<< " = " << (compare_date(date) * value) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

std::string	trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start == std::string::npos || end == std::string::npos)
		return ("");

	return (str.substr(start, end - start + 1));
}
