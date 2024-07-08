/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:05:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/08 17:53:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << BLUE"" << "Hi! I'm <<no one>>" << NC"" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name) : name(_name)
{
	std::cout << BLUE"" << "Hi! I'm " << this->name << NC"" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE"" << "Bye bye! (" << this->name << ")" << NC"" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name)
{
	std::cout << BLUE"Copy constructor called for " << NC"" << other.name << std::endl;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);

	std::cout << BLUE"Assignment operator called for " << other.name << NC"" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (this->name);
}

void	ClapTrap::setName(std::string _name)
{
	this->name = _name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints < 1)
	{
		std::cout << YELLOW"" << this->name << " cannot atack because has 0 energy points" << NC"" << std::endl;
		return ;
	}
	std::cout << RED"" << this->name << " attacks " << target <<
	", causing " << this->attackDamage << " points of damage!" << NC"" << std::endl;
	this->energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints >= 10)
	{
		std::cout << YELLOW"" << this->name << " is fully repaired, save that energy for later" << NC"" << std::endl;
		return;
	}
	
	if (this->energyPoints <= 0)
	{
		std::cout << YELLOW"" << this->name << " does not have enough energy to repair" << NC"" << std::endl;
		return;
	}
	
	if ((this->hitPoints + amount) > 10)
		this->hitPoints = 10;
	else
		this->hitPoints += amount;
	
	std::cout << GREEN"" << this->name << " has been repaired, now has " << this->hitPoints
	<< " hit points" << NC"" << std::endl;
	this->energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << RED_B"" << this->name << " has been attacked, he lost " << amount << " hit points!" << NC"" << std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0)
	{
		std::cout << YELLOW"" << this->name << "cannot attack. He's too tired" << NC"" << std::endl;
		return ;
	}
}