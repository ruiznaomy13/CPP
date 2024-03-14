/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:32:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/14 16:57:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanA(Weapon _weapon);
		~HumanA();

		void	attack(void);
};

#endif