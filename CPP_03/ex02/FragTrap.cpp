/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:18:46 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 13:22:25 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "<<no one>>";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << CYAN"" <<"[FragTrap] Hi! I'm <<no one>>" << NC"" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN"" << "[FragTrap] Hi! I'm " << _name << NC"" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << CYAN"[FragTrap] Copy constructor called for "<< other._name
	<< NC"" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this == &other)
        return *this;
    ClapTrap::operator=(other);
    std::cout << CYAN"[FragTrap] Copy assignment operator called for " << other._name
	<< NC"" << std::endl;
    return (*this);
}
FragTrap::~FragTrap()
{
	std::cout << CYAN"" << "[FragTrap] Bye bye! (" << _name << ")" << NC"" << std::endl; 
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN"[FragTrap] " << _name << ": GIVE ME FIVE !!"
	<< NC"" <<std::endl;
}
