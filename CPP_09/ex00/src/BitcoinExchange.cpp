/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:29:26 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/03 19:13:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos) {
        return ""; // La cadena contiene solo espacios
    }

    return str.substr(start, end - start + 1);
}

BitcoinExchange::BitcoinExchange(std::string _file_name)
{
    this->file_name = _file_name;
    save_data("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::getFileName() const
{
    return (file_name);
}

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
		{
			error_msg("Error: bad line.");
			continue ;
		}

		date = cast_date(date_str);
		if (date.year == 0 && date.month == 0 && date.day == 0)
		{
			error_msg("Error: Invalid date.");
			continue ;
		}

		value = std::atof(value_str.c_str());
		Data[date] = value;
	}
}

Date	BitcoinExchange::cast_date(std::string& date_str)
{
    int year = 0, month = 0, day = 0;
	date_str = trim(date_str);

    if (sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        error_msg("Error: Invalid date format. Expected YYYY-MM-DD.");
        return (Date){0, 0, 0};
    }

    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        error_msg("Error: Invalid date values.");
        return (Date){0, 0, 0};
    }

    return (Date){year, month, day};
}

void	BitcoinExchange::error_msg(const std::string& msg) const
{
    std::cerr << msg << std::endl;
}

void	BitcoinExchange::show_data() const // QUITAR
{
    for (std::map<Date, float>::const_iterator it = Data.begin(); it != Data.end(); ++it)
    {
        std::cout << it->first.year << "-"
                  << (it->first.month < 10 ? "0" : "") << it->first.month << "-"
                  << (it->first.day < 10 ? "0" : "") << it->first.day
                  << " -> " << it->second << std::endl;
    }
}

float	BitcoinExchange::compare_date(Date date) const
{
	std::map<Date, float>::const_iterator	it = Data.lower_bound(date);

	if (it == Data.end() || !(date < it->first))
	{
		if (it != Data.begin())
			--it;
		else
			return (-1.0f);
	}
	return (it->second);
}

void	BitcoinExchange::output_info( void )
{
    std::ifstream	file(file_name.c_str());
    std::string		line;
    float			value;
	Date			date;

	if (!file)
	{
		error_msg("Error: Cannot open file " + file_name);
		return ;
	}
	
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date_str, value_str;

		if (!std::getline(ss, date_str, '|') || !std::getline(ss, value_str)) {
			std::cerr << "Error: Malformed line -> " << line << std::endl;
			continue ;
		}

		date = cast_date(date_str);
		if (date.year == 0 && date.month == 0 && date.day == 0) {
			error_msg("Error: Invalid date.");
			continue ;
		}
		value = std::atof(value_str.c_str());
		// try
		// {
			std::cout << trim(date_str) << " => " << value
			<< " = " << (compare_date(date) * value) << std::endl;
		// } catch () {
			
		// }
	}
	
}
