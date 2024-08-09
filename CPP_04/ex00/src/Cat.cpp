/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:12:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] created" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat] destroyed" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << " miau miau " << std::endl;
}
