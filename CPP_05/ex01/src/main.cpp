/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/01 16:34:24 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/Form.hpp"

int main(void)
{
	{
		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat(71);
		Form *b = new Form(70, 70);
		std::cout << std::endl;

		std::cout << "        >>>>>>>>>>> Testing <<<<<<<<<<<<" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch (std::exception& e)
		{
			a->signForm(*b);
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << "        >>>>>>>>>>> Testing <<<<<<<<<<<<" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		// Assistant signs the Form
		try
		{
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "" << std::endl;
		}

		// CEO signs the Form
		std::cout << c;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "" << std::endl;
		}
		std::cout << c;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "Deconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "Constructing" << std::endl;
		Form *a = NULL;

		// sign-grade too high
		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "" << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "" << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "" << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "Deconstructing" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	return (0);
}
