/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 18:17:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	_contact_number = 0;
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
	_contact[_contact_number].setFirstName(firstName);
	_contact[_contact_number].setLastName(lastName);
	_contact[_contact_number].setNickName(nickName);
	_contact[_contact_number].setPhoneNumber(phoneNumber);
	std::cout << GREEN"\nSAVED CORRECTLY ✅\n" << std::endl;
	std::cin.get();
};

// Hacer un funcion de display 
void	PhoneBook::showContact(int )
{
	std::cout << CYAN"\n    ---- CONTACT INFO ----" << std::endl;
	std::cout << _contact[0].getFirstName() << std::endl;
	std::cout << _contact[0].getLastName() << std::endl;
	std::cout << _contact[0].getNickName() << std::endl;
	std::cout << _contact[0].getPhoneNumber() << std::endl;
	std::cout << NC"" << std::endl;
	std::cin.get();
}
