/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:12:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 14:02:24 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructpor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other); 
    return (*this);
}

Cat::~Cat()
{
    std::cout << "[Cat] destroyed" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << " miau miau " << std::endl;
}
