/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:32:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 20:36:21 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA(std::string name, Weapon& _weapon);
		HumanA(Weapon& _weapon);
		~HumanA();

		void	attack(void);
};

#endif