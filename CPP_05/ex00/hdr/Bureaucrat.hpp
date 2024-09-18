/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/18 17:07:17 by ncastell         ###   ########.fr       */
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
		Bureaucrat(int garde);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int garde);
		~Bureaucrat();

		std::string getName() const;
		int	getGrade() const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif