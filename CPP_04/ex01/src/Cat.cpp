/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:12:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 00:44:03 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "[Cat] Created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	std::cout << "[Cat] Assignment operator called" << std::endl;
	Animal::operator=(other);
	delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "[Cat] Destroyed" << std::endl;
}

Brain*	Cat::getBrain( void )
{
	return (_brain);
} 

void	Cat::makeSound( void ) const
{
	std::cout << " miau miau " << std::endl;
}
