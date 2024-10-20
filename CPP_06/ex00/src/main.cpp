/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:34:41 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 20:58:58 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
	if (ac != 2) {
		std::cout << "Try this: " << av[0] << " <input>" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
