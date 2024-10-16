/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:28:53 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/16 18:18:51 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

#define NUM_FORMS 3

class	AForm;
class	PresidentialPardonForm;
class	RobotomyRequestForm;
class	ShrubberyCreationForm;
class	Bureaucrat;

class Intern
{
	private:
		struct FormType
		{
			const char *formName;
			AForm *(*createFormFunction)(std::string target);
		};

		FormType	formTypes[NUM_FORMS];

		static AForm	*createPresidentialPardon(std::string target);
		static AForm	*createRobotomyRequest(std::string target);
		static AForm	*createShrubberyCreation(std::string target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator = (const Intern& other);
		~Intern();

		void toUpperStr(std::string &str);
		AForm *makeForm(std::string name, std::string target);
};

#endif