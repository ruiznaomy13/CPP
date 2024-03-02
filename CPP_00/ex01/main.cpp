/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:09 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/28 14:24:21 by ncastell         ###   ########.fr       */
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
		// system("clear");
		std::cout << NC"What would you wanna do?\n- ADD\n- SEARCH\n- EXIT\n" << std::endl;
		std::getline(std::cin, action);
		action = ft_toUpperCase(action);

		if (action == "ADD")
			phoneBook.saveContactInfo();
		else if (action == "SEARCH")
		{
			// phoneBook.searchContact();
			// std::cout << "Num contact: " << std::endl;
			// std::getline(std::cin, str_index);
			// index = atoi(str_index.c_str());
			phoneBook.searchContact(); // como poner esto bien?
		}
		else if (action == "EXIT" || action == "exit")
			return 0;
		else {
            std::cout << "Invalid choice. Please try again." << std::endl;
			std::cout << "Press enter to continue ..." << std::endl;
			std::cin.get();
		}
	}
}
