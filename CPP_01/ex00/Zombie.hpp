/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:34:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/11 20:34:24 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	
	void	announce(void);

	// getters
	std::string	getName(void);
	
	// setters
	void	setName(std::string name);
};

//heap
Zombie	*newZombie(std::string name);

//stack
void	randomChump(std::string name);

#endif