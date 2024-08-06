/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:49:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 13:27:01 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	// ScavTrap	scav1;
	// ScavTrap	scav2("Pochito");
	// ScavTrap	scav3("Chacalito");
	// ScavTrap	scav4(scav2);
	
	// scav4.setName("Rogelio");
	// scav1 = scav3;
	// scav1.attack(scav2.getName());
	// scav2.takeDamage(5);
	// scav1.guardGate();

	/*  FRAGTRAP  */
	FragTrap	frag1;
	FragTrap	frag2("Titan");
	FragTrap	frag3("Cucumber");
	FragTrap	frag4(frag2);
	
	frag4.setName("Rogelio");
	frag1 = frag3;
	frag1.attack(frag2.getName());
	frag2.takeDamage(5);
	frag1.highFivesGuys();
}