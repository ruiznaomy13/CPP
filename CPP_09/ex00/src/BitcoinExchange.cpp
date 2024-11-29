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

BitcoinExchange::BitcoinExchange(std::string file_name)
{
	_file_name = file_name;
}

BitcoinExchange::~BitcoinExchange()
{}

std::string	BitcoinExchange::getFileName()
{
	return (_file_name);
}