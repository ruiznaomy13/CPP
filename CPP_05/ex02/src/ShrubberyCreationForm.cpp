/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:17:12 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/08 14:00:28 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
AForm("<target> Presidential Pardon Form", MIN_SIGN_PPF, MIN_EXEC_PPF)
{
	std::cout << BLUE"[ShrubberyCreationForm] Constructor called" << NC"" << std::endl;
	_target = "<target>";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
AForm(target + " Presidential Pardon Form", MIN_SIGN_PPF, MIN_EXEC_PPF)
{
	std::cout << BLUE"[ShrubberyCreationForm] Constructor called" << NC"" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << BLUE"[ShrubberyCreationForm] Copy constructor called" << NC"" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	std::cout << BLUE"[ShrubberyCreationForm] Assignment operator called" << NC"" << std::endl;
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED"[ShrubberyCreationForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}

void    ShrubberyCreationForm::executeImplement( void ) const {
	std::cout << GREEN"" << _target << " has been pardoned by Zaphod Beeblebrox." << \
	NC"" << std::endl;
}

std::string ShrubberyCreationForm::getErrorMsg( void ) const {
	return (_target + " hasn't been pardoned by Zaphod Beeblebrox.");
}