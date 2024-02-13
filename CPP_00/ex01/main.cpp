/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:09 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/13 15:07:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	std::string	action;

	std::cout << "What would you wanna do?\n- SEARCH\n" << std::endl;
	std::cin >> action;

	if (action == "SEARCH")
	{
		std::cout << "Give me the first name: " << std::endl;
	}
}