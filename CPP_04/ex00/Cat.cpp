/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:12:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/07 16:10:40 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] created" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat] destroyed" << std::endl;
}

void	Cat::makeSound( void )
{
	std::cout << " miau miau " << std::endl;
}
