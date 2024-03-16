/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:12 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 23:11:13 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA Bobby("Bobby", club);
		Bobby.attack();
		club.setType("some other type of club");
		Bobby.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Jimmy("Jimmy");
		Jimmy.attack();
		Jimmy.setWeapon(club);
		Jimmy.attack();
		club.setType("some other type of club");
		Jimmy.attack();
	}
}