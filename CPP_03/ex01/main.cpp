/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:49:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 12:00:29 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// ClapTrap    clap1("Kood");
	// ClapTrap    clap2("Porki");
	// ClapTrap	clap3;

	// clap3 = clap1;
	// clap1.beRepaired(3);
	// clap1.attack(clap2.getName());
	// clap1.attack(clap2.getName());
	// clap1.takeDamage(5);
	// clap2.attack(clap1.getName());
	// clap2.takeDamage(8);
	// clap3.setName("NeNa");
	// clap3.takeDamage(9);
	// clap3.beRepaired(6);
	// clap2.beRepaired(6);

	/*  SCAVTRAP  */
	ScavTrap	scav1;
	ScavTrap	scav2("Pochito");
	ScavTrap	scav3("chacalito");
	ScavTrap	scav4(scav2);
	
	scav4.setName("Rogelio");
	scav1 = scav3;
	scav1.attack(scav2.getName());
	scav2.takeDamage(5);
	scav1.guardGate();
}