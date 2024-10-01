/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/01 16:23:30 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"
 /* Constructors */
Bureaucrat::Bureaucrat() : _name("<<no one>>"), _grade(150) {
    std::cout << BLUE"[BUREAUCRAT] Constructor called ()" << NC"" << std::endl;
}
 
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) { 
    std::cout << BLUE"[BUREAUCRAT] Constructor called (" << _name << ")" << NC"" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("<<no one>>"), _grade(grade) {
    std::cout << BLUE"[BUREAUCRAT] Constructor called (" << _grade << ")" << NC"" << std::endl;
	if (_grade < 1) {
        throw GradeTooHighException();
    } else if (_grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << BLUE"[BUREAUCRAT] Constructor called (" << _name << ", "<< _grade<< ")" << NC"" << std::endl;
	if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << BLUE"[BUREAUCRAT] Copy constructor called for " << this->_name << NC"" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
    if (this == &other)
        return (*this);
    std::cout << BLUE"[BUREAUCRAT] Assignment operator called for " << this->getName() << NC"" << std::endl;
    this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED"[BUREAUCRAT] " << _name << " Destructor called for " << this->_name << NC"" << std::endl;
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

/* Functions */
void    Bureaucrat::decrementGrade( void ) {
    if (_grade > 149) { throw GradeTooLowException(); }
    _grade++;
}

void    Bureaucrat::incrementGrade( void ) {
    if (_grade < 2) { throw GradeTooHighException(); }
    _grade--;
}

void    Bureaucrat::signForm(Form& form) {
    if (form.getSign()) {
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } else {
        std::cout << this->getName() << " couldn't sign " << form.getName() << \
        " because the grade is too low!" << std::endl;
    }
}

/* Exceptions */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The highest possible grade is 1!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The lowest possible grade is 150!!");
}

/* insertion operator overload */
std::ostream& operator<<(std::ostream& out, const Bureaucrat* bureaucrat)
{
    out << "[BUREAUCRAT]\n" << bureaucrat->getName() << ", grade " << bureaucrat->getGrade() << std::endl;
    return (out);
}