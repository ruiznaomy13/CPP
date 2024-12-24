/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:29:26 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/29 18:41:58 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string _file_name)
{
	this->file_name = _file_name;
	save_data("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::getFileName()
{
	return file_name;
}

void	BitcoinExchange::save_data(std::string data_file)
{
	std::ifstream	file(data_file.c_str());
	std::string		line;
	Date			date;
	float			value;

	std::cout << data_file.c_str() << std::endl;
	if (!file) {
		error_msg("ERROR: Cannot open file");
		return;
	}

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date_str, value_str;

		if (!std::getline(ss, date_str, ',') || !std::getline(ss, value_str)) {
			error_msg("Error: bad line.");
			continue;
		}

		date = cast_date(date_str);
		value = std::atof(value_str.c_str());

		Data[date] = value;
	}
}

Date	BitcoinExchange::cast_date(const std::string& date_str)
{
	int year = 0, month = 0, day = 0;

	if (sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		error_msg("Error: Invalid date format. Expected YYYY-MM-DD.");
		Date invalid_date = {0, 0, 0};
		return invalid_date; // Devuelve una fecha predeterminada
	}

	if (month < 1 || month > 12 || day < 1 || day > 31) {
		error_msg("Error: Invalid date values.");
		Date invalid_date = {0, 0, 0};
		return (invalid_date);
	}

	Date valid_date = {year, month, day};
	return (valid_date);
}

void	BitcoinExchange::error_msg(std::string msg)
{
	std::cerr << msg << std::endl;
}

void	BitcoinExchange::show_data() const
{
	for (std::map<Date, float>::const_iterator it = Data.begin(); it != Data.end(); ++it) {
		std::cout << it->first.year << "-"
				<< (it->first.month < 10 ? "0" : "") << it->first.month << "-"
				<< (it->first.day < 10 ? "0" : "") << it->first.day
				<< " -> " << it->second << std::endl;
	}
}

