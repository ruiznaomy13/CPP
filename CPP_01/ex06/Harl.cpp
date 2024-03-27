/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/27 17:06:02 by ncastell         ###   ########.fr       */
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
	int	start = -1;

	for (int i = 0; i < N_LEVELS; i++)
	{
		if (level == levels[i])
			start = i;
	}
	switch (start)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "\n      [ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << GREEN"[ DEBUG ]" << std::endl;
	std::cout << WHITE"I need more sunflowers to protect my garden from the zombies!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE"[ INFO ]" << std::endl;
	std::cout <<  WHITE"I've discovered that sunflowers are crucial for collecting resources and defending against zombies.\n";
	std::cout <<  "It's important to plant more sunflowers to keep us prepared!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW"[ WARNING ]" << std::endl;
	std::cout << WHITE"Something's wrong with my sunflower plant, it seems sick. I should check it before the zombies attack it.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED"[ ERROR ]" << std::endl;
	std::cout << WHITE"My plants are being destroyed by the zombies! I need urgent help to save my garden!\n" << std::endl;
}
