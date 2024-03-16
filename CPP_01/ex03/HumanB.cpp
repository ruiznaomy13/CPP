/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:51:46 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 23:09:58 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	this->name = "[someone]";
	this->weapon->setType("bare-knuckle");
}

HumanB::HumanB(std::string _name) : name(_name)
{
	this->weapon->setType("bare-knuckle");
}

HumanB::HumanB(std::string _name, Weapon* _weapon) : name(_name), weapon(_weapon)
{}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	this->weapon = &_weapon;
}

void	HumanB::setName(std::string _name)
{
	this->name = _name;
}

void	HumanB::attack(void)
{
	std::cout << name << " attack with their " << weapon->getType() << std::endl;
}
