/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:59:04 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/26 16:50:25 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
		return (NULL);
	Zombie*	zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	return zombies;
}
