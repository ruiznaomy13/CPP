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

void	PhoneBook::errorMsg(int error)
{
	if (error == 1)
		std::cout << "Input empty, please enter a correct input:" << std::endl;
}

void PhoneBook::saveContactInfo()
{
    std::string firstName, lastName, nickName, phoneNumber;

    // Leer cada dato
    std::cout << "First Name: ";
    while (std::getline(std::cin, firstName) && firstName.empty()) {errorMsg(1);}

    std::cout << "Last Name: ";
    while (std::getline(std::cin, lastName) && lastName.empty()) {errorMsg(1);}

    std::cout << "Nick Name: ";
    while (std::getline(std::cin, nickName) && nickName.empty()) {errorMsg(1);}
    
    std::cout << "Phone number: ";
    while (std::getline(std::cin, phoneNumber) && phoneNumber.empty()) {errorMsg(1);}

    // Guardar la información en el contacto
    _contact[_contactNumber].setFirstName(firstName);
    _contact[_contactNumber].setLastName(lastName);
    _contact[_contactNumber].setNickName(nickName);
    _contact[_contactNumber].setPhoneNumber(phoneNumber);
	std::cout << _contactNumber << std::endl;
	if (_contactNumber == 2)
    {
        for (int i = 0; i < 2; i++)
            _contact[i] = _contact[i + 1];
        std::cerr << "Warning: The phonebook is full!" << std::endl;
    }
	if (_contactNumber < 2)
    	_contactNumber++;
    std::cout << "\nSAVED CORRECTLY ✅\n" << std::endl;
    std::cout << "Press enter to continue ..." << std::endl;
    std::cin.get();
}

void    PhoneBook::searchContact(void)
{
    int         i;
    std::string index;

    if (!_contactNumber)
    {
        std::cerr << "There are no contacts" << std::endl;
        return ;
    }
    for (i = 0; i < _contactNumber; i++)
    {
        _contact[i].showContact(i);
	}
}

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
