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

void	Contact::showContact(int index)
{
	std::string str[4];

	str[0] = index + 49;
	str[1] = _firstName;
	str[2] = _lastName;
	str[3] = _nickName;

	for (int i = 0; i < 4; i++)
	{
		if (str[i].length() > 10)
			std::cout << str[i].substr(0, 9) << ".";
		else {
			std::cout << str[i];
			for (size_t j = str[i].length(); j < 10; j++)
                std::cout << " ";
		}
		std::cout << " | ";
	}
	std::cout << std::endl;
}

void	Contact::showFullContact(int index)
{
	std::cout << _firstName << std::endl;
	std::cout << _lastName << std::endl;
	std::cout << _nickName << std::endl;
	std::cout << _phoneNumber << std::endl;
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
