/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/07 21:01:15 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/AForm.hpp"
#include "../hdr/PresidentialPardonForm.hpp"

void	PresidentialPardonFormTest() {
	try {
		Bureaucrat	bob("Bob", 5);
		Bureaucrat	tedy("tedy", 25);
		Bureaucrat	tedy2;
		tedy2 = tedy;
		tedy2.decrementGrade();
		std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
		std::cout << tedy.getName() << " has a grade of " << tedy.getGrade() << std::endl;
		std::cout << tedy2.getName() << " has a grade of " << tedy2.getGrade() << std::endl;

		// Crear un formulario de perdón presidencial
		PresidentialPardonForm pp_form("Target Person");
		std::cout << "Created pp_form: " << pp_form.getName() << std::endl;

		// Intentar ejecutar el formulario sin firmarlo
		try {
			// "Trying to execute pp_form without signing..."
			pp_form.execute(bob);
		} catch (const AForm::NotSignedForm& e) {
			std::cerr << YELLOW"Error: " << e.what() << NC"" << std::endl;
		}

		// Firmar el pp_formulario
		bob.signForm(pp_form);

		// Intentar ejecutar el pp_formulario después de firmarlo
		try {
			// with signing
			pp_form.execute(bob);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy.signForm(pp_form);
		try {
			// with signing but not the grade
			pp_form.execute(tedy);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy2.signForm(pp_form);
		try {
			// with signing but not the grade
			pp_form.execute(tedy2);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << YELLOW"An error occurred: " << e.what() << NC""  << std::endl;
	}
}

int main()
{
	PresidentialPardonFormTest();

	return 0;
}

