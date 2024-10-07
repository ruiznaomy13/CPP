/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/07 13:59:09 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/AForm.hpp"
#include "../hdr/PresidentialPardonForm.hpp"

int main()
{
	try {
		// Crear un Bureaucrat
		Bureaucrat bob("Bob", 5); // Nombre y grado
		Bureaucrat tedy("Bob", 15);
		std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;

		// Crear un formulario de perdón presidencial
		PresidentialPardonForm pp_form("TargetPerson");
		std::cout << "Created pp_form: " << pp_form.getName() << std::endl;

		// Intentar ejecutar el formulario sin firmarlo
		try {
			std::cout << "Trying to execute pp_form without signing..." << std::endl;
			pp_form.execute(bob);
		} catch (const AForm::NotSignedForm& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		// Firmar el pp_formulario
		bob.signForm(pp_form);
		std::cout << bob.getName() << " signed the pp_form." << std::endl;

		// Intentar ejecutar el pp_formulario después de firmarlo
		try {
			std::cout << "Executing the pp_form now..." << std::endl;
			pp_form.execute(bob);
		} catch (const std::exception& e) {
			std::cerr << "Execution failed: " << e.what() << std::endl;
		}

		tedy.signForm(pp_form);
		try {
			std::cout << "Executing the pp_form now..." << std::endl;
			pp_form.execute(tedy);
		} catch (const std::exception& e) {
			std::cerr << "Execution failed: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}

	return 0;
}

