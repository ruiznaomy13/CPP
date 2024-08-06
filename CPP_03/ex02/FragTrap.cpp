/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:18:46 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 12:34:31 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "no one";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN"" <<"[ScavTrap] Hi! I'm <<no one>>" << NC"" << std::endl;
}