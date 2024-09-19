/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/19 16:24:44 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
 /* Constructors */
Bureaucrat::Bureaucrat(int grade) : _name("default"), _grade(grade) {
	if (_grade < 1) {
        throw GradeTooHighException();
    } else if (_grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {}

/* Getters */
std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (_grade);
}

/* Increment && Decrement functions */
void    Bureaucrat::decrementGrade( void ) {
    if (_grade > 149) { throw GradeTooLowException(); }
    _grade++;
}

void    Bureaucrat::incrementGrade( void ) {
    if (_grade < 2) { throw GradeTooHighException(); }
    _grade--;
}

/* Exceptions */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The highest possible grade is 1!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The lowest possible grade is 150!!");
}

/* insertion operator overload */
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}