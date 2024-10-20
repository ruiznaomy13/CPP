/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:00:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 21:34:15 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter() {
	std::cout << "[SCALAR CONVERTER] Constructor Called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "[SCALAR CONVERTER] Copy Constructor." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "[SCALAR CONVERTER] Copy Assignmet Operator." << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "[SCALAR CONVERTER] Destructor." << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal)) // nan, inf
		return (handlePseudoLiteral(literal));
	if (isCharLiteral(literal)) // 1 caracter
		return (printChar(static_cast<double>(literal[0])));

	char* end;
	double value;

	if (!literal.empty() && literal[literal.size() - 1] == 'f') {
		std::string lit_trim = literal.substr(0, literal.length() - 1);
		value = std::strtod(lit_trim.c_str(), &end);
	} else {
		value = std::strtod(literal.c_str(), &end);
	}

	if (*end != '\0') {
		std::cout << "Conversion impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(static_cast<float>(value));
	printDouble(value);
}

void ScalarConverter::printChar(double value)
{
	if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << "" << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "float: " \
		<< static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << value << "" << std::endl;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (1);
	else if (literal == "nan"  || literal == "+inf"  || literal == "-inf")
		return (1);
	return (0);
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (literal == "+inff" || literal == "+inf")	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (literal == "-inff" || literal == "-inf")	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (1);
	return (0);
}
