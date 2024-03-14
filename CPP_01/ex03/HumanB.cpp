/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:51:46 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/14 16:56:16 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string _name, Weapon _weapon)
{
	this->name = _name;
	this->weapon = _weapon;
}

HumanB::HumanB(std::string _name)
{
	this->name = _name;
}

HumanB::~HumanB()
{
}
