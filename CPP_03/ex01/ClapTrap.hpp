/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:50:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/06 12:08:33 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define RED		"\x1b[31m"
# define RED_B		"\x1b[1;31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define WHITE		"\e[1;37m"
# define CYAN		"\x1b[1;36m"
# define MAGENTA	"\033[95m"
# define NC			"\033[0m"

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other); // copy constructor
		ClapTrap& operator = (const class ClapTrap& other);
		~ClapTrap();
		
		std::string	getName(void);
		void		setName(std::string name);

		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
};

#endif