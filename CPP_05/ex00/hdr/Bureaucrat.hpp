/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/19 16:18:29 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int garde);
		// copy assignment operator
		// copy default constructor
		~Bureaucrat();

		std::string getName() const;
		int	getGrade() const;

		void	incrementGrade( void );
		void	decrementGrade( void );

		// customized exception TooHighGRade
		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		// customized exception TooLowGRade
		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif