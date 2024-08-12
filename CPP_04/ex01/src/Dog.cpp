/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:31:31 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 18:00:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "[Dog] Created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	std::cout << "[Dog] Assignment operator called" << std::endl;
	Animal::operator=(other);
	delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "[Dog] Destroyed" << std::endl;
}

std::string Dog::getBrainIdea(int pos_idea)
{
    return (_brain->ideas[pos_idea]);
}

void    Dog::setBrainIdeas(std::string idea, int pos_idea)
{
    _brain->ideas[pos_idea] = idea;
}

void	Dog::makeSound( void ) const
{
	std::cout << " woof woof " << std::endl;
}
