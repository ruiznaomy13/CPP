/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/06 15:41:26 by ncastell         ###   ########.fr       */
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
		std::cout << RED"ERROR: Invalid choice. Please try again." << std::endl;
	if (error == 1)
		std::cerr << RED"Error: please enter a correct input: ";
	if (error == 2)
		std::cerr << YELLOW"Warning: There are no contacts" << std::endl;
	if (error == 3)
		std::cout << RED"ERROR: Invalid contact number." << std::endl;
	if (error == 4)
		std::cerr << YELLOW"Warning: The phonebook is full!" << std::endl;
	if (error != 1 && error != 4) {
		std::cout << WHITE"\nPress enter to continue ..." << std::endl;
		std::cin.get();
	}
	std::cout << NC"";
}

void	PhoneBook::successMsg(int type)
{
	if (type == 1)
		std::cout << GREEN"\nSAVED CORRECTLY ✅" << std::endl;
	std::cout << WHITE"\nPress enter to continue ..." << std::endl;
	std::cin.get();
}

void	PhoneBook::saveContactInfo()
{
    std::string firstName, lastName, nickName, phoneNumber, darkSecret;

    std::cout << "First Name: ";
    while (!std::getline(std::cin, firstName) || firstName.empty()) {errorMsg(1);}
    std::cout << "Last Name: ";
    while (!std::getline(std::cin, lastName) || lastName.empty()) {errorMsg(1);}
    std::cout << "Nick Name: ";
    while (!std::getline(std::cin, nickName) || nickName.empty()) {errorMsg(1);}
    std::cout << "Phone number: ";
    while (!std::getline(std::cin, phoneNumber) || phoneNumber.empty() \
	|| isNum(phoneNumber)) { errorMsg(1); }
    std::cout << "Darkest Secret: ";
    while (std::getline(std::cin, darkSecret) && darkSecret.empty()) {errorMsg(1);}

	if (_contactNumber == MAX_CONTACTS) {
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			_contact[i] = _contact[i + 1];
		errorMsg(4);
		_contactNumber--;
	}
    _contact[_contactNumber].setFirstName(firstName);
    _contact[_contactNumber].setLastName(lastName);
    _contact[_contactNumber].setNickName(nickName);
    _contact[_contactNumber].setPhoneNumber(phoneNumber);
	_contact[_contactNumber].setDarkSecret(darkSecret);

	if (_contactNumber < MAX_CONTACTS)
		_contactNumber++;

    successMsg(1);
}

void PhoneBook::searchContact(void)
{
    std::string index;
    int         n_index;

    if (!_contactNumber)
        return errorMsg(2);
	std::cout << "\n     INDEX |       NAME |  LAST NAME |  NICK NAME" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
    for (int i = 0; i < _contactNumber; i++)
        _contact[i].showContact(i);
    std::cout << CYAN"\nNum contact: " << std::endl;
    if (!std::getline(std::cin, index))
        return ;
    if (isNum(index))
        return errorMsg(3);
    n_index = std::atoi(index.c_str());
    if (n_index > 0 && n_index <= _contactNumber)
        _contact[n_index - 1].showFullContact();
    else
        return (errorMsg(3));
	successMsg(0);
}

void	PhoneBook::showContact(int index)
{
	std::cout << _contact[index].getFirstName() << std::endl;
	std::cout << _contact[index].getLastName() << std::endl;
	std::cout << _contact[index].getNickName() << std::endl;
	std::cout << _contact[index].getPhoneNumber() << std::endl;
	std::cout << NC"" << std::endl;
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