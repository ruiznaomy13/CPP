/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/16 18:59:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/AForm.hpp"
#include "../hdr/PresidentialPardonForm.hpp"
#include "../hdr/RobotomyRequestForm.hpp"
#include "../hdr/ShrubberyCreationForm.hpp"
#include "../hdr/Intern.hpp"

#include <iostream>

int main()
{
	Intern intern;

	Bureaucrat bob("Bob", 26);

	std::cout << WHITE"\n\t--------------- TEST 1 ----------------" << NC"" << std::endl;
	AForm *pardonForm = intern.makeForm("presidential pardon", "Alice");
	if (pardonForm)
	{
		std::cout << "Created form: " << pardonForm->getName() << std::endl;
		bob.signForm(*pardonForm);
		bob.executeForm(*pardonForm);
		delete pardonForm;
	}

	std::cout << WHITE"\n\t--------------- TEST 2 ----------------" << NC"" << std::endl;
	AForm *robotomyForm = intern.makeForm("robotomy request", "Bender");
	if (robotomyForm)
	{
		std::cout << "Created form: " << robotomyForm->getName() << std::endl;
		bob.signForm(*robotomyForm);
		bob.executeForm(*robotomyForm);
		delete robotomyForm;
	}

	std::cout << WHITE"\n\t--------------- TEST 3 ----------------" << NC"" << std::endl;
	AForm *shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
	if (shrubberyForm)
	{
		std::cout << "Created form: " << shrubberyForm->getName() << std::endl;
		bob.signForm(*shrubberyForm);
		bob.executeForm(*shrubberyForm);
		delete shrubberyForm;
	}

	std::cout << WHITE"\n\t--------------- TEST 4 ----------------" << NC"" << std::endl;
	AForm *unknownForm = intern.makeForm("non-existent form", "Unknown");
	if (unknownForm)
	{
		std::cout << "Created form: " << unknownForm->getName() << std::endl;
		bob.signForm(*unknownForm);
		bob.executeForm(*unknownForm);
		delete unknownForm;
	}
	return 0;
}



