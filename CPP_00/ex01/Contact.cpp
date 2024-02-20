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
