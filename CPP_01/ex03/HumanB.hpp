/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:51:34 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 23:08:38 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "HumanA.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
		
	public:
		HumanB();
		HumanB(std::string _name);
		HumanB(std::string _name, Weapon* _weapon);
		~HumanB();
		
		// setters
		void	setWeapon(Weapon& _weapon);
		void	setName(std::string name);

		void	attack(void);
};

#endif