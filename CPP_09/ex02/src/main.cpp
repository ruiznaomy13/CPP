/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:49:16 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/22 15:58:23 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
    * positive numbers

    - Ford-Johnson algorithm
    - Handle at least 3000 integers
    - Implement your algorithm for each container and thus to avoid using a generic function
*/

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "ERROR: Debes proporcionar al menos un número como argumento." << std::endl;
		return (1);
	}

	PmergeMe	FordJohnson;

	FordJohnson.fill_vector(ac, av);
	FordJohnson.print_vector();
}