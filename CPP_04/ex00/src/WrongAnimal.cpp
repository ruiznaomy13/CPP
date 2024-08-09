/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:07:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/09 17:19:31 by ncastell         ###   ########.fr       */
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