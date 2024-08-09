/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:08:13 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/09 17:28:43 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] created" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destroyed" << std::endl;
}

void	WrongCat::makeSound( void )
{
	std::cout << " miau miau " << std::endl;
}
