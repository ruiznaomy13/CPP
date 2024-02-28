/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 19:00:46 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	_contactNumber = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::saveContactInfo(void)
{
	std::string	firstName, lastName, nickName, phoneNumber;

	// getInfo
	std::cout << "First Name: " << std::endl;
	std::getline(std::cin, firstName);

	std::cout << "Last Name: " << std::endl;
	std::getline(std::cin, lastName);

	std::cout << "Nick Name: " << std::endl;
	std::getline(std::cin, nickName);
	
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);

	// saveInfo
	_contact[_contactNumber].setFirstName(firstName);
	_contact[_contactNumber].setLastName(lastName);
	_contact[_contactNumber].setNickName(nickName);
	_contact[_contactNumber].setPhoneNumber(phoneNumber);
	_contactNumber++;
	std::cout << GREEN"\nSAVED CORRECTLY ✅\n" << std::endl;
	std::cout << NC"Press enter to continue ..." << std::endl;
	std::cin.get();
};

// Hacer un funcion de display 
void	PhoneBook::showContact(int index)
{
	std::cout << CYAN"\n    ---- CONTACT INFO ----" << std::endl;
	std::cout << _contact[index].getFirstName() << std::endl;
	std::cout << _contact[index].getLastName() << std::endl;
	std::cout << _contact[index].getNickName() << std::endl;
	std::cout << _contact[index].getPhoneNumber() << std::endl;
	std::cout << NC"" << std::endl;
	std::cout << "Press enter to continue ..." << std::endl;
	std::cin.get();
}
