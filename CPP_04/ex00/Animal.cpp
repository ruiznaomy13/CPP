/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:02:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/07 13:38:34 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

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

std::string	Animal::getType( void )
{
	return (_type);
}
