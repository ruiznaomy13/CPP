/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:09 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 17:56:27 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	action;

	while (22)
	{
		system("clear");
		std::cout << NC"What would you wanna do?\n- ADD\n- SEARCH\n- EXIT\n" << std::endl;
		std::getline(std::cin, action);
		
		if (action == "ADD")
			phoneBook.saveContactInfo();
		else if (action == "SEARCH")
			phoneBook.showContact();
		else
            std::cout << "Invalid choice. Please try again." << std::endl;
	}
}