/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:31:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/09 13:37:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Form.hpp"

/* Constructors */
Form::Form() : _name("<<any form>>"), _sign(false), _signGrade(150), _execGrade(150)
{
	std::cout << BLUE"[FORM] Constructor called []" << NC"" << std::endl;
}

Form::Form(std::string name) : _name(name), _sign(false), _signGrade(150), _execGrade(150)
{
	std::cout << BLUE"[FORM] Constructor called (" << _name << ")" \
	<< NC"" << std::endl;
}

Form::Form(short int signGrade, short int execGrade) : \
_name("<<any form>>"), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
	checkGrades(_execGrade);
	checkGrades(_signGrade);
	std::cout << BLUE"[FORM] Constructor called (" << _name << ", " \
	<< _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

Form::Form(std::string name, short int signGrade, short int execGrade) : \
_name(name), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
	checkGrades(_execGrade);
	checkGrades(_signGrade);
	std::cout << BLUE"[FORM] Constructor called (" << _name << ", " \
	<< _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), \
_signGrade(other._signGrade),_execGrade(other._execGrade) {
	std::cout << BLUE"[FORM] Copy constructor called for " << \
	this->_name << NC"" << std::endl;
}

Form& Form::operator = (const Form& other) {
	if (this == &other)
		return (*this);
	std::cout << BLUE"[FORM] Assignment operator called for " << \
	this->getName() << NC"" << std::endl;
	this->_sign = other._sign;
	return (*this);
}

Form::~Form() {
	std::cout << RED"[FORM] " << _name << " Destructor called for " << \
	this->_name << NC"" << std::endl;
}

/* Getters */
bool    Form::getSign( void ) const {
	return (this->_sign);
}

int Form::getExecGrade( void ) const {
	return (this->_execGrade);
}

int Form::getSignGrade( void ) const {
	return (this->_signGrade);
}

std::string Form::getName( void ) const {
	return (this->_name);
}

/* Functions */
void    Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)	{
		throw GradeTooLowException();
	}
	this->_sign = true;
}

void    Form::checkGrades(short int grade)
{
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

/* Ecetions */
const char* Form::GradeTooHighException::what() const throw() {
    return ("The highest possible grade is 1!!");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("The grade it's too low!!");
}

/* insertion operator overload */
std::ostream& operator<<(std::ostream& out, const Form* form) {
	out << "[FORM]\nName: " << form->getName() << \
	"\nSign grade: " << form->getSignGrade() << \
	"\nExecution grade: " << form->getExecGrade() << std::endl;
	if (form->getSign()) {
		std::cout << "Sign: YES" << std::endl;
	} else {
		std::cout << "Sign: NO" << std::endl;
	}
	return (out);
}