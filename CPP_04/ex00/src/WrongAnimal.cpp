/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:07:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 13:38:11 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("<<no_type>>")
{
	std::cout << "[WrongAnimal] " << _type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "[WrongAnimal] " << _type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] Copy constructpor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	std::cout << "[WrongAnimal] Assignment operator called for " << other._type << std::endl;
	this->_type = other._type;
	return(*this);	
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destroyed" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "  * NOT SOUND *  " << std::endl;
}