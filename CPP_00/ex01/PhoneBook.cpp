/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/04 20:18:56 by ncastell         ###   ########.fr       */
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
	if (error == 0)
		std::cout << "Invalid choice. Please try again." << std::endl;
	if (error == 1)
		std::cerr << "Input empty, please enter a correct input:" << std::endl;
	if (error == 2)
		std::cerr << "There are no contacts" << std::endl;
	if (error == 3)
		std::cout << "Invalid contact number." << std::endl;
	std::cout << "Press enter to continue ..." << std::endl;
}

void PhoneBook::saveContactInfo()
{
    std::string firstName, lastName, nickName, phoneNumber, darkSecret;

    // Leer cada dato
    std::cout << "First Name: ";
    while (std::getline(std::cin, firstName) && firstName.empty()) {errorMsg(1);}

    std::cout << "Last Name: ";
    while (std::getline(std::cin, lastName) && lastName.empty()) {errorMsg(1);}

    std::cout << "Nick Name: ";
    while (std::getline(std::cin, nickName) && nickName.empty()) {errorMsg(1);}
    
    std::cout << "Phone number: ";
    while (std::getline(std::cin, phoneNumber) && phoneNumber.empty()) {errorMsg(1);}

    std::cout << "Darkest Secret: ";
    while (std::getline(std::cin, darkSecret) && darkSecret.empty()) {errorMsg(1);}

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

void PhoneBook::searchContact(void)
{
    std::string index;
    int         n_index;

    if (!_contactNumber)
        return errorMsg(2);
    for (int i = 0; i < _contactNumber; i++)
        _contact[i].showContact(i);
    std::cout << "Num contact: " << std::endl;
    if (std::getline(std::cin, index))
        return ;
    if (isNum(index))
        return errorMsg(3);
    n_index = std::atoi(index.c_str());
    if (n_index >= 0 && n_index < _contactNumber){
        _contact[n_index].showFullContact();
		std::cout << _contactNumber << std::endl;
	}
    else
        errorMsg(3);
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

int     PhoneBook::isNum(std::string str)
{
    size_t i;

    if (str.length() == 0)
        return (1);
    for (i = 0; i < str.length(); i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
    }
    return (0);
}