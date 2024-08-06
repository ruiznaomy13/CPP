/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:05:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 12:04:15 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << BLUE"" << "[ClapTrap] Hi! I'm <<no one>>" << NC"" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name) : _name(_name)
{
	std::cout << BLUE"" << "[ClapTrap] Hi! I'm " << _name << NC"" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE"" << "[ClapTrap] Bye bye! (" << _name << ")" << NC"" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << BLUE"[ClapTrap] Copy constructor called for " << other._name  << NC"" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);

	std::cout << BLUE"[ClapTrap] Assignment operator called for " << other._name << NC"" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_attackDamage = other._attackDamage;
	_energyPoints = other._energyPoints;
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints < 1)
	{
		std::cout << YELLOW"" << _name << " cannot atack because has 0 energy points"
		<< NC"" << std::endl;
		return ;
	}
	std::cout << RED"" << _name << " attacks " << target <<
	", causing " << _attackDamage << " points of damage!" << NC"" << std::endl;
	_energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints >= 10)
	{
		std::cout << YELLOW"" << _name << " is fully repaired, save that energy for later"
		<< NC"" << std::endl;
		return;
	}
	
	if (_energyPoints <= 0)
	{
		std::cout << YELLOW"" << _name << " does not have enough energy to repair"
		<< NC"" << std::endl;
		return;
	}
	
	if ((_hitPoints + amount) > 10)
		_hitPoints = 10;
	else
		_hitPoints += amount;
	
	std::cout << GREEN"" << _name << " has been repaired, now has " << _hitPoints
	<< " hit points" << NC"" << std::endl;
	_energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << RED_B"" << _name << " has been attacked, he lost " << amount
	<< " hit points!" << NC"" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << YELLOW"" << _name << "cannot attack. He's too tired" << NC"" << std::endl;
		return ;
	}
}