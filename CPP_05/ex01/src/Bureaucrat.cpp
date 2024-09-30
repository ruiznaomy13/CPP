/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/30 13:31:54 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
 /* Constructors */
Bureaucrat::Bureaucrat() : _name("<<no one>>"), _grade(150) {
    std::cout << BLUE"Constructor called []" << NC"" << std::endl;
}
 
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) { 
    std::cout << BLUE"Constructor called [" << _name << "]" << NC"" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("<<no one>>"), _grade(grade) {
    std::cout << BLUE"Constructor called [" << _grade << "]" << NC"" << std::endl;
	if (_grade < 1) {
        throw GradeTooHighException();
    } else if (_grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << BLUE"Constructor called [" << _name << ", "<< _grade<< "]" << NC"" << std::endl;
	if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << BLUE"Copy constructor called for " << this->_name << NC"" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
    if (this == &other)
        return (*this);
    std::cout << BLUE"Assignment operator called for " << this->getName() << NC"" << std::endl;
    this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED"[" << _name << "] Destructor called for " << this->_name << NC"" << std::endl;
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