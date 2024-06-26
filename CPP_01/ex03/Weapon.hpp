/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:10:52 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/15 17:08:28 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		// getters
		const std::string	getType(void);
		
		// setters
		void	setType(std::string _type);
};

#endif