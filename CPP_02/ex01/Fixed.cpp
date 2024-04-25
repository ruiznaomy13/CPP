/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:24:08 by ncastell          #+#    #+#             */
/*   Updated: 2024/04/25 10:50:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int _num) : num(_num)
{
	std::cout << "Int constructor called" << std::endl;
	num = _num << rawBits;
}

Fixed::Fixed(const float _num) : num(_num)
{
	std::cout << "Float constructor called" << std::endl;
	num = roundf(_num * pow(2, rawBits));
}

Fixed::Fixed(const Fixed& other) : num(other.num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy  assignment operator called" << std::endl;
	if (this != &other)
		this->num = other.getRawBits();
	return (*this);
}

// Getter and setter
int	Fixed::getRawBits(void) const
{
	return (this->num);
}

void	Fixed::setRawBits(const int raw)
{
	this->num = raw;
}


/* MEMBER FUNCTIONS */
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(num) / pow(2, rawBits));
}

int	Fixed::toInt(void) const
{
	return (num >> rawBits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}