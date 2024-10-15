/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/15 21:17:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
#include "../hdr/AForm.hpp"
#include "../hdr/PresidentialPardonForm.hpp"
#include "../hdr/RobotomyRequestForm.hpp"
#include "../hdr/ShrubberyCreationForm.hpp"
#include "../hdr/Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	AForm	*rrf;

	rrf = someRandomIntern.makeForm("Robotomy request", "Bender");

	delete rrf;

	return (0);
}

