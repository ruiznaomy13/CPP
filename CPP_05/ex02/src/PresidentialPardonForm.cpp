/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:13:01 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/07 13:42:35 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
AForm(target + "Presidential Pardon Form", MIN_SIGN_PPF, MIN_EXEC_PPF)
{
    std::cout << BLUE"[PresidentialPardonForm] Constructor called" << NC"" << std::endl;
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED"[PresidentialPardonForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}

void    PresidentialPardonForm::executeImplement(Bureaucrat& executor) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getErrorMsg( void ) const {
    return (_target + "hasn't been pardoned by Zaphod Beeblebrox.");
}
