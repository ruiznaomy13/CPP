/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:02:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 01:50:06 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Animal.hpp"

Animal::Animal() : _type("<<no_type>>")
{
	std::cout << "[Animal] " << _type << " created" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "[Animal] " << _type << " created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "[Animal] Copy constructpor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	std::cout << "[Animal] Assignment operator called for " << other._type << std::endl;
	this->_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] destroyed" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (_type);
}
