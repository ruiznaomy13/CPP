/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:51:34 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/14 16:57:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "HumanA.hpp"

class HumanB
{
private:
	std::string name;
	Weapon weapon;
public:
	HumanB();
	HumanB(std::string name, Weapon _weapon);
	HumanB(std::string name);
	~HumanB();

	void	attack(void);
};

#endif