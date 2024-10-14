/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/14 20:26:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/AForm.hpp"
#include "../hdr/PresidentialPardonForm.hpp"
#include "../hdr/RobotomyRequestForm.hpp"
#include "../hdr/ShrubberyCreationForm.hpp"

void	PresidentialPardonFormTest()
{
	try {
		Bureaucrat	bob("Bob", 5);
		Bureaucrat	tedy("tedy", 25);
		Bureaucrat	tedy2;
		tedy2 = tedy;
		tedy2.decrementGrade();
		std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
		std::cout << tedy.getName() << " has a grade of " << tedy.getGrade() << std::endl;
		std::cout <<tedy2.getName() << " has a grade of " << tedy2.getGrade() << std::endl;

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

void	RobotomyRequestFormTest()
{
	try {
		Bureaucrat	bob("Bob", 40);
		Bureaucrat	tedy("tedy", 72);
		Bureaucrat	tedy2(tedy);

		tedy2.decrementGrade();
		std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
		std::cout << tedy.getName() << " has a grade of " << tedy.getGrade() << std::endl;
		std::cout <<tedy2.getName() << " has a grade of " << tedy2.getGrade() << std::endl;

		// Crear un formulario de perdón presidencial
		RobotomyRequestForm rr_form("Target Person");
		std::cout << "Created rr_form: " << rr_form.getName() << std::endl;

		// Intentar ejecutar el formulario sin firmarlo
		try {
			// "Trying to execute rr_form without signing..."
			rr_form.execute(bob);
		} catch (const AForm::NotSignedForm& e) {
			std::cerr << YELLOW"Error: " << e.what() << NC"" << std::endl;
		}

		// Firmar el rr_formulario
		bob.signForm(rr_form);

		// Intentar ejecutar el rr_formulario después de firmarlo
		try {
			// with signing
			rr_form.execute(bob);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy.signForm(rr_form);
		try {
			// with signing but not the grade
			rr_form.execute(tedy);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy2.signForm(rr_form);
		try {
			// with signing but not the grade
			rr_form.execute(tedy2);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << YELLOW"An error occurred: " << e.what() << NC""  << std::endl;
	}
}

void	ShrubberyCreationFormTest()
{
	try {
		Bureaucrat	bob("Bob", 40);
		Bureaucrat	tedy("tedy", 137);
		Bureaucrat	nao("Nao", 146);
		Bureaucrat	tedy2(tedy);

		tedy2.decrementGrade();
		
		std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
		std::cout << tedy.getName() << " has a grade of " << tedy.getGrade() << std::endl;
		std::cout <<tedy2.getName() << " has a grade of " << tedy2.getGrade() << std::endl;

		// Crear un formulario de perdón presidencial
		ShrubberyCreationForm sc_form("Target Person");
		std::cout << "Created sc_form: " << sc_form.getName() << std::endl;

		try {
			// "Trying to execute sc_form without signing..."
			nao.signForm(sc_form);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Error signing: " << e.what() << NC"" << std::endl;
		}

		// Intentar ejecutar el formulario sin firmarlo
		try {
			// "Trying to execute sc_form without signing..."
			sc_form.execute(bob);
		} catch (const AForm::NotSignedForm& e) {
			std::cerr << YELLOW"Error: " << e.what() << NC"" << std::endl;
		}

		// Firmar el sc_formulario
		bob.signForm(sc_form);

		// Intentar ejecutar el sc_formulario después de firmarlo
		std::cout << "TESTING" << std::endl;
		try {
			// with signing
			sc_form.execute(bob);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy.signForm(sc_form);
		try {
			// with signing but not the grade
			tedy.executeForm(sc_form);
			// sc_form.execute(tedy);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}

		tedy2.signForm(sc_form);
		try {
			// with signing but not the grade
			sc_form.execute(tedy2);
		} catch (const std::exception& e) {
			std::cerr << YELLOW"Execution failed: " << e.what() << NC""  << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << YELLOW"An error occurred: " << e.what() << NC""  << std::endl;
	}
}

int main()
{
	// PresidentialPardonFormTest();
	// RobotomyRequestFormTest();
	ShrubberyCreationFormTest();

	return 0;
}

