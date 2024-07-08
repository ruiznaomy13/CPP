/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:49:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/08 17:51:08 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap    player1("Kood");
	ClapTrap    player2("Porki");
	ClapTrap	player3;

	player3 = player1;
	player1.beRepaired(3);
	player1.attack(player2.getName());
	player1.attack(player2.getName());
	player1.takeDamage(5);
	player2.attack(player1.getName());
	player2.takeDamage(8);
	player3.setName("NeNa");
	player3.takeDamage(9);
	player3.beRepaired(6);
	player2.beRepaired(6);
}