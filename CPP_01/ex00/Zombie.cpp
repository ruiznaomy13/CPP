/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:43:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/11 20:26:42 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << ": another zombie down, one less to worry about. 🪓" << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

std::string	Zombie::getName(void)
{
	return _name;
}

void	Zombie::announce()
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ... 🧟" << std::endl;
}
