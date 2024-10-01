/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:32:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/01 16:16:08 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_sign;
		
		void	checkGrades(int grade);
	public:
		Form();
		Form(std::string name);
		Form(int signGrade, int execGrade);
		Form(std::string name, int signGrade, int execGrade);
		~Form();

		/* GETTERS */
		std::string	getName( void ) const;
		bool		getSign( void ) const;
		int			getExecGrade( void ) const;
		int			getSignGrade( void ) const;

		/* FUNCTIONS */
		void	beSigned(Bureaucrat& bureaucrat);
		
		/* EXCEPTIONS */
		class	GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form* form);

#endif