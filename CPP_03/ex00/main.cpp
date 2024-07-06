/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:49:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/06 14:05:35 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    player1("Kood");
    ClapTrap    player2("Porki");

    player1.beRepaired(3);
    player1.attack(player2.getName());
    player1.takeDamage(5);
    player2.attack(player1.getName());
    player2.takeDamage(3);
    player1.beRepaired(6);
}