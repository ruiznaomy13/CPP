/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/09 13:52:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/Form.hpp"

int main(void)
{
	{
		Bureaucrat *a = new Bureaucrat(71);
		Form *b = new Form(70, 69);
		std::cout << std::endl;

		std::cout << GREEN"\t>>>>>>>>>>>>>>>>>>>>>> Testing <<<<<<<<<<<<<<<<<<<<<<<<" << NC"\n" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(std::exception& e)
		{
			std::cerr << YELLOW"" << a->getName() << " was not able to sign the Form " << \
			b->getName() << ": " << e.what() << NC"" << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		delete a;
		delete b;
		std::cout << std::endl;
	}

	std::cout << "-----------------------------------------------------------------\n" << std::endl;

	{
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << GREEN"\t>>>>>>>>>>>>>>>>>>>>>> Testing <<<<<<<<<<<<<<<<<<<<<<<<" << NC"\n" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		// Assistant signs the Form
		try
		{
			a->signForm(*c);
		}
		catch(std::exception& e)
		{
			std::cerr << YELLOW"" << a->getName() << " was not able to sign the Form " << \
			c->getName() << ": " << e.what() << NC"" << std::endl;
		}

		// CEO signs the Form
		std::cout << c << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(std::exception& e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << \
			c->getName() << ": " << e.what() << NC"" << std::endl;
		}
		std::cout << c << std::endl;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}

	std::cout << "------------------------------------------------------------------\n" << std::endl;

	{
		std::cout << GREEN"\t>>>>>>>>>>>>>>>>>>>>>> Testing <<<<<<<<<<<<<<<<<<<<<<<<" << NC"\n" << std::endl;	
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

		if (a != NULL)
			delete a;
	}
	return (0);
}
