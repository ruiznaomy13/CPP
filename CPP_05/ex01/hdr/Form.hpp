/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:32:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/09 13:16:03 by ncastell         ###   ########.fr       */
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
		bool				_sign;
		const short int		_signGrade;
		const short int		_execGrade;
		
		void	checkGrades(short int grade);

	public:
		Form();
		Form(std::string name);
		Form(short int signGrade, short int execGrade);
		Form(std::string name, short int signGrade, short int execGrade);
		Form(const Form& other);
		Form& operator = (const Form& other);
		
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