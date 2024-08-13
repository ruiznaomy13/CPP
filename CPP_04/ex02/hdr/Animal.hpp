/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:57 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 01:51:01 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define RED		"\x1b[1;31m"
# define GREEN		"\x1b[1;32m"
# define BLUE		"\x1b[34m"
# define WHITE		"\e[1;37m"
# define CYAN		"\x1b[36m"

/* CLASE ABSTRACTA */
class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator = (const Animal& other);
		virtual	~Animal();

		std::string	getType( void ) const;
		virtual	void	makeSound( void ) const = 0; // metodo virtual
};

#endif