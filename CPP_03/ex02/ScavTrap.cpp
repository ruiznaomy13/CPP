/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:56:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 13:20:01 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "<<no one>>";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN"" <<"[ScavTrap] Hi! I'm <<no one>>" << NC"" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN"" << "[ScavTrap] Hi! I'm " << _name << NC"" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << CYAN"[ScavTrap] Copy constructor called for "<< other._name
	<< NC"" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this == &other)
        return *this;
    ClapTrap::operator=(other);
    std::cout << CYAN"[ScavTrap] Copy assignment operator called for " << other._name
	<< NC"" << std::endl;
    return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << CYAN"" << "[ScavTRap] Bye bye! (" << _name << ")" << NC"" << std::endl; 
}

void	ScavTrap::guardGate(void)
{
	std::cout << GREEN"[ScavTrap] " << _name << " in Gate keeper mode."
	<< NC"" <<std::endl;
}
