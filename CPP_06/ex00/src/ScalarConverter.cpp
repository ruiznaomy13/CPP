/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:00:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/17 17:25:22 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ScalarConverter.hpp"
#include <cstdlib>   // para atof y strtod
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>    // para std::isdigit

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	// Detecta si es un pseudo-literal (nan, inf, etc.)
	if (isPseudoLiteral(literal))
	{
		handlePseudoLiteral(literal);
		return;
	}

	// Detecta si es un literal de un solo carácter
	if (isCharLiteral(literal))
	{
		printChar(static_cast<double>(literal[0]));
		return;
	}

	char* end;
	double value;

	// Detecta si es un float con sufijo 'f'
	if (!literal.empty() && literal[literal.size() - 1] == 'f')
	{
		std::string trimmedLiteral = literal.substr(0, literal.length() - 1);  // Removemos el sufijo 'f'
		value = std::strtod(trimmedLiteral.c_str(), &end);

		if (*end != '\0') // Si hay un carácter no válido después del número
		{
			std::cout << "Conversion impossible\n";
			return;
		}

		printChar(value);
		printInt(value);
		printFloat(static_cast<float>(value));  // Para el caso float, mantenemos el sufijo 'f'
		printDouble(value);
	}
	else
	{
		// Caso normal sin el sufijo 'f'
		value = std::strtod(literal.c_str(), &end);

		if (*end != '\0')
		{
			std::cout << "Conversion impossible\n";
			return;
		}

		printChar(value);
		printInt(value);
		printFloat(static_cast<float>(value));
		printDouble(value);
	}
}

// Imprime las conversiones para un char
void ScalarConverter::printChar(double value)
{
	if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
	{
		std::cout << "char: Non displayable\n";
	}
	else if (value >= 32 && value <= 126)
	{
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	}
	else
	{
		std::cout << "char: Non displayable\n";
	}
}

// Imprime las conversiones para un int
void ScalarConverter::printInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
}

// Imprime las conversiones para un float
void ScalarConverter::printFloat(double value)
{
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f\n";
}

// Imprime las conversiones para un double
void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << value << "\n";
}

// Manejo de pseudo-literals (nan, inf, etc.)
bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (1);
	if (literal == "nan"  || literal == "+inf"  || literal == "-inf")
		return (1);
	return (0);
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "nan") 
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	} else if (literal == "+inff" || literal == "+inf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	} else if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

// Detecta si es un literal de un solo carácter
bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (1);
	return (0);
}
