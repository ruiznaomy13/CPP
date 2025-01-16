/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:03:35 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/16 14:38:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	rpn;
	
	if (ac != 2)
		return (-1);

	try {
		rpn.calculator(av[1]);
	} catch (const std::exception& e) {
		std::cerr << RED"" << e.what() << NC"" << std::endl;
	}
	return (0);
}
