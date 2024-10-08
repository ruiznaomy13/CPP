/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:13:01 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/08 12:48:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
AForm("<target> Presidential Pardon Form", MIN_SIGN_PPF, MIN_EXEC_PPF)
{
	std::cout << BLUE"[PresidentialPardonForm] Constructor called" << NC"" << std::endl;
	_target = "<target>";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
AForm(target + " Presidential Pardon Form", MIN_SIGN_PPF, MIN_EXEC_PPF)
{
	std::cout << BLUE"[PresidentialPardonForm] Constructor called" << NC"" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	std::cout << BLUE"[PresidentialPardonForm] Copy constructor called" << NC"" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	std::cout << BLUE"[PresidentialPardonForm] Assignment operator called" << NC"" << std::endl;
	AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED"[PresidentialPardonForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}

void    PresidentialPardonForm::executeImplement( void ) const {
	std::cout << GREEN"" << _target << " has been pardoned by Zaphod Beeblebrox." << \
	NC"" << std::endl;
}

std::string PresidentialPardonForm::getErrorMsg( void ) const {
	return (_target + " hasn't been pardoned by Zaphod Beeblebrox.");
}
