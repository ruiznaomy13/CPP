/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:08:13 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 13:40:19 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this == &other)
        return (*this);
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
    this->_type = other._type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destroyed" << std::endl;
}

void	WrongCat::makeSound( void )
{
	std::cout << " miau miau " << std::endl;
}
