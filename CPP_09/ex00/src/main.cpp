/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:56:18 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/08 19:11:10 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	
	BitcoinExchange	btc(av[1]);
	btc.output_info();
}