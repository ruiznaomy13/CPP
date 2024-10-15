/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:28:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/15 19:42:13 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Intern.hpp"

// Intern::Intern()
// {
//     std::cout << BLUE"[INTERN] Constructor called" << std::endl;
//     formTypes[0] = FormType{"PRESIDENTIAL PARDON", createPresidentialPardon};
//     formTypes[1] = FormType{"ROBOTOMY REQUEST", createRobotomyRequest};
//     formTypes[2] = FormType{"SHRUBBERY CREATION", createShrubberyCreation};
//     formTypes[3] = FormType{0, 0};
// }

Intern::Intern() {
    formTypes[0] = FormType("PRESIDENTIAL PARDON", createPresidentialPardon);
    formTypes[1] = FormType("ROBOTOMY REQUEST", createRobotomyRequest);
    formTypes[2] = FormType("SHRUBBERY CREATION", createShrubberyCreation);
}

Intern::~Intern()
{
    std::cout << RED"[INTERN] Destructor called" << std::endl;
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

AForm   *Intern::makeForm(std::string name, std::string target)
{
	toUpperStr(name);
	for (int i = 0; formTypes[i].formName != 0; ++i)
	{
		if (name == formTypes[i].formName)
			return (formTypes[i].createFormFunction(target));
	}
	std::cerr << "Unknown form type: " << name << std::endl;
	return (0);
}