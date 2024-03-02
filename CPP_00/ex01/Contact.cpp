/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:33:33 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 17:28:30 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}


void    Contact::showContact(int index)
{
    std::cout << "entra en display" << std::endl;
    int n = 4;
    std::string str[n];

    str[0] = index + 49;
    str[1] = _firstName;
    str[2] = _lastName;
    str[3] = _nickName;

    for (int i = 0; i < n; i++)
    {
        if (str[i].length() > 10)
			std::cout << str[i].erase(0, 9);
		else
			std::cout << str[i];
        std::cout << " | ";
    }

    std::cout << std::endl;
}

/* SETTERS */
void	Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}


/* GETTERS */
std::string	Contact::getFirstName(void) {
	return (_firstName);
}

std::string	Contact::getLastName(void) {
	return (_lastName);
}

std::string	Contact::getNickName(void) {
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) {
	return (_phoneNumber);
}
