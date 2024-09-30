/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define NC			"\033[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int garde);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator = (const Bureaucrat& other);
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