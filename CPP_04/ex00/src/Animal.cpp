/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:02:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:41 by ncastell         ###   ########.fr       */
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

Animal::~Animal()
{
	std::cout << "[Animal] destroyed" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "  * NOT SOUND *  " << std::endl;
}
