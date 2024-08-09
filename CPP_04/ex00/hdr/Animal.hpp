/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:57 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/09 16:58:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string type);
		virtual	~Animal();

		std::string	getType( void ) const;
		virtual	void	makeSound( void ) const; // un metodo abstracto obliga a redefinirlos
};

#endif