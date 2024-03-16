/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 17:10:09 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* Constructor && Destructor */
Weapon::Weapon(std::string _type) : type(_type) {}
Weapon::Weapon() {}
Weapon::~Weapon() {}

/* Getters && Setters */
void	Weapon::setType(std::string _type)
{
	this->type = _type;
}
const std::string	Weapon::getType(void)
{ 
	return (this->type);
}

