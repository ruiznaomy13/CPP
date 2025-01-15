/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:03:35 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/15 18:06:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	RNP	calculator;
	
	if (ac != 2)
		return (-1);

	calculator.rpn(av[1]);
	return (0);
}
