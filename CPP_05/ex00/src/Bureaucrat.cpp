/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/18 17:09:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
 /* Constructors */
Bureaucrat::Bureaucrat(int grade) : _name("default"), _grade(grade) {
	
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	
}

/* Getters */
std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (_grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}