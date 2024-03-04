/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:09 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/04 20:14:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

std::string ft_toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
	
	return (str);
}

// void	strToInt(std::string &str)
// {
// 	char *
// }

int	main()
{
	PhoneBook	phoneBook;
	std::string	action;
	std::string	str_index;
	// int			index;

	while (true)
	{
		system("clear");
		std::cout << NC"What would you wanna do?\n- ADD\n- SEARCH\n- EXIT\n" << std::endl;
		if (!std::getline(std::cin, action))
			return EXIT_FAILURE;
		action = ft_toUpperCase(action);
		if (action == "ADD")
			phoneBook.saveContactInfo();
		else if (action == "SEARCH")
			phoneBook.searchContact();
		else if (action == "EXIT")
			return EXIT_SUCCESS;
		else
			phoneBook.errorMsg(0);
		std::cin.get();
	}
}
