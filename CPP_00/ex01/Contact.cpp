/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:33:33 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/05 19:31:58 by ncastell         ###   ########.fr       */
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
			std::cout << std::setw(10);
			std::cout << str[i];
		}
			std::cout << "|";
	}
	std::cout << std::endl;
}

void	Contact::showFullContact(void)
{
	std::cout << CYAN"\n    ---- CONTACT INFO ----" << std::endl;
	std::cout << WHITE"First name: " << NC"" << _firstName << std::endl;
	std::cout << WHITE"Last name: " << NC"" << _lastName << std::endl;
	std::cout << WHITE"Nick name: " << NC"" << _nickName << std::endl;
	std::cout << WHITE"Phone number: " << NC"" << _phoneNumber << std::endl;
	std::cout << WHITE"Darkest secret:\n" << NC"" << _darkSecret << std::endl;
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

void	Contact::setDarkSecret(std::string darkSecret) {
	_darkSecret = darkSecret;
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

std::string	Contact::getDarkSecret(void) {
	return (_darkSecret);
}