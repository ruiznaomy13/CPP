/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/21 18:13:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	complaints[0] = &Harl::debug;
	complaints[1] = &Harl::info;
	complaints[2] = &Harl::warning;
	complaints[3] = &Harl::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Harl::~Harl() {}

void    Harl::complain(std::string level)
{
	for (int i = 0; i < N_LEVELS; i++)
	{
		if (level == levels[i]) {
			(this->*complaints[i])();
			std::cout << WHITE"";
			return ;
		}
	}
	std::cout << "Seems everything is OK!" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << GREEN"I need more sunflowers to protect my garden from the zombies!" << std::endl;
}

void	Harl::info(void)
{
	std::cout <<  BLUE"I've discovered that sunflowers are crucial for collecting resources and defending against zombies." ;
	std::cout <<  "It's important to plant more sunflowers to keep us prepared!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW"Something's wrong with my sunflower plant, it seems sick. I should check it before the zombies attack it." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED"My plants are being destroyed by the zombies! I need urgent help to save my garden!" << std::endl;
}
