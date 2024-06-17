/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:24:08 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/17 19:07:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int _num) : num(_num)
{
	num = _num << rawBits;
}

Fixed::Fixed(const float _num) : num(_num)
{
	num = roundf(_num * pow(2, rawBits));
}

Fixed::Fixed(const Fixed& other) : num(other.num)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
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

/* OVERLOADING OPERATOR FUNCTIONS */
// Aritmethic
Fixed	Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// Comparision
bool	Fixed::operator>(const class Fixed& compared) const
{
	if (this->num > compared.num)
		return (true);
	return (false);
}

bool	Fixed::operator<(const class Fixed& compared) const
{
	if (this->num < compared.num)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const class Fixed& compared) const
{
	if (this->num >= compared.num)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const class Fixed& compared) const
{
	if (this->num <= compared.num)
		return (true);
	return (false);
}

bool	Fixed::operator==(const class Fixed& compared) const
{
	if (this->num == compared.num)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const class Fixed& compared) const
{
	if (this->num != compared.num)
		return (true);
	return (false);
}

// Incre/Decre-ment
Fixed&  Fixed::operator++(void)
{
	++this->num;
	return (*this);
}

Fixed  Fixed::operator++(int)
{
	Fixed a(*this);
	a.setRawBits(this->num++);
	return (a);
}

Fixed&  Fixed::operator--(void)
{
	--this->num;
	return (*this);
}

Fixed  Fixed::operator--(int)
{
	Fixed a(*this);
	a.setRawBits(this->num--);
	return (a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.num > b.num)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.num < b.num)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.num > b.num)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.num < b.num)
		return (a);
	return (b);
}


std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}