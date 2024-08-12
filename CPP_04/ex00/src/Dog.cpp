/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:31:31 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 14:02:39 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "[Dog] created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructpor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other); 
    return (*this);
}

Dog::~Dog()
{
    std::cout << "[Dog]  destroyed" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << " woof woof " << std::endl;
}
