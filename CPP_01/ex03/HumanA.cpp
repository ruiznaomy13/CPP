/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:16 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 20:36:53 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon)
{}

HumanA::HumanA(Weapon& _weapon) : weapon(_weapon)
{
	this->name = "[someone]";
}

HumanA::~HumanA() {}

void	HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << std::endl;
}