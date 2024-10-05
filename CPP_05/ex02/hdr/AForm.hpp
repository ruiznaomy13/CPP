/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:32:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/05 12:32:43 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#define	MIN_SIGN 25
#define	MIN_EXEC 5

class Bureaucrat;

class AForm
{
	private:
		bool				_sign;
		const std::string	_name;
		const short int		_signGrade;
		const short int		_execGrade;

		void	checkGrades(short int grade);
	public:
		AForm();
		AForm(std::string name, short int signGrade, short int execGrade);
		AForm(const AForm& other);
		AForm& operator = (const AForm& other);
		
		virtual ~AForm();

		/* GETTERS */
		std::string	getName( void ) const;
		bool		getSign( void ) const;
		int			getExecGrade( void ) const;
		int			getSignGrade( void ) const;

		/* FUNCTIONS */
		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat& executor) const = 0; // polimorfismo

		/* EXCEPTIONS */
		class	GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class NotSignedForm : public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm* Aform);

#endif