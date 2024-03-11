/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:34:31 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/11 20:33:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*myZombie;

	myZombie = newZombie("Lolita");
	delete	myZombie;
	randomChump("Cerebrito"); 
}