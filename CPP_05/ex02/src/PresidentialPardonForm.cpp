/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:13:01 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/05 17:09:24 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : \
AForm(target + "Presidential Pardon Form", MIN_SIGN, MIN_EXEC)
{
    std::cout << BLUE"[PresidentialPardonForm] Constructor called []" << NC"" << std::endl;
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED"[PresidentialPardonForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}