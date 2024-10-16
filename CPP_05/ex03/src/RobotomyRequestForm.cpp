/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:15:50 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/16 18:12:24 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
AForm("Robotomy Pardon", MIN_SIGN_RRF, MIN_EXEC_RRF)
{
    std::cout << BLUE"[RobotomyRequestForm] Constructor called" << NC"" << std::endl;
    _target = "<target>";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
AForm("Robotomy Pardon", MIN_SIGN_RRF, MIN_EXEC_RRF)
{
    std::cout << BLUE"[RobotomyRequestForm] Constructor called" << NC"" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    std::cout << BLUE"[RobotomyRequestForm] Copy constructor called" << NC"" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this == &other)
        return (*this);
    std::cout << BLUE"[RobotomyRequestForm] Assignment operator called" << NC"" << std::endl;
    AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED"[RobotomyRequestForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}

void    RobotomyRequestForm::executeImplement( void ) const {
    std::cout << WHITE"\t\tBEEP... BOOP... BEEP... BOOP..." << NC"" << std::endl;
    std::cout << GREEN"" << _target << " has been robotomized successfully 50% of the time" \
    << NC"" << std::endl;
}

std::string RobotomyRequestForm::getErrorMsg( void ) const {
    return (_target + " robotomy failed");
}
