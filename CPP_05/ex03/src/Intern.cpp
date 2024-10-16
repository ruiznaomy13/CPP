/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:28:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/16 18:58:32 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Intern.hpp"

Intern::Intern()
{
	std::cout << BLUE "[INTERN] Constructor called" << NC"" << std::endl;

	formTypes[0].formName = "PRESIDENTIAL PARDON";
	formTypes[0].createFormFunction = createPresidentialPardon;

	formTypes[1].formName = "ROBOTOMY REQUEST";
	formTypes[1].createFormFunction = createRobotomyRequest;

	formTypes[2].formName = "SHRUBBERY CREATION";
	formTypes[2].createFormFunction = createShrubberyCreation;
}

Intern::Intern(const Intern& other)
{
	std::cout << BLUE"[INTERN] Copy Constructor Called" << NC""<< std::endl;
	for (int i = 0; i < NUM_FORMS; ++i)
	{
		formTypes[i].formName = other.formTypes[i].formName;
		formTypes[i].createFormFunction = other.formTypes[i].createFormFunction;
	}
}

Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	std::cout << "[Intern] Assignment Operator called" << std::endl;
	for (int i = 0; i < NUM_FORMS; ++i)	{
		formTypes[i].formName = other.formTypes[i].formName;
		formTypes[i].createFormFunction = other.formTypes[i].createFormFunction;
	}
	return (*this);
}

Intern::~Intern()
{
    std::cout << RED"[INTERN] Destructor called" << NC"" << std::endl;
}

AForm *Intern::createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

void	Intern::toUpperStr(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	toUpperStr(name);
	for (int i = 0; i < NUM_FORMS; ++i)
	{
		if (name == formTypes[i].formName)
			return (formTypes[i].createFormFunction(target));
	}
	std::cerr << YELLOW "Unknown form type: " << name << NC"" << std::endl;
	return (0);
}

