/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:01:43 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/17 16:56:27 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define WHITE		"\x1b[1;37m"
# define NC			"\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

		static bool isPseudoLiteral(const std::string& literal);
		static void handlePseudoLiteral(const std::string& literal);
		static bool isCharLiteral(const std::string& literal);

	public:
		static void convert(const std::string& literal);
};

#endif

