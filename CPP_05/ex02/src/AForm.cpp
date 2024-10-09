/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:31:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/05 17:01:45 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/AForm.hpp"

/* Constructors */
AForm::AForm() : _name("<<no one>>"), _signGrade(150), _execGrade(150) {
	std::cout << BLUE"[AFORM] Constructor called []" << NC"" << std::endl;
}

AForm::AForm(std::string name, short int signGrade, short int execGrade) : \
_name(name), _signGrade(signGrade), _execGrade(execGrade) {
	checkGrades(_execGrade);
	checkGrades(_signGrade);
	std::cout << BLUE"[AFORM] Constructor called (" << _name << ", " \
	<< _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _sign(other._sign), \
_signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << BLUE"[AFORM] Copy constructor called for " << this->_name << NC"" << std::endl;
}

AForm& AForm::operator = (const AForm& other) {
	if (this == &other)
		return (*this);
	std::cout << BLUE"[AFORM] Assignment operator called for " << \
	this->getName() << NC"" << std::endl;
	/* TODO */
	return (*this);
}

AForm::~AForm() {
	std::cout << RED"[AFORM] Destructor called for " << \
	this->_name << NC"" << std::endl;
}

/* Getters */
bool    AForm::getSign( void ) const {
	return (this->_sign);
}

int AForm::getExecGrade( void ) const {
	return (this->_execGrade);
}

int AForm::getSignGrade( void ) const {
	return (this->_signGrade);
}

std::string AForm::getName( void ) const {
	return (this->_name);
}

/* Functions */
void    AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)	{
		throw GradeTooLowException();
	}
	this->_sign = true;
}

void	AForm::execute(Bureaucrat& executor) const
{
	try {
		checkExecute(executor);
		executeImplement();
	}
	catch (const std::exception& e) {
		std::cerr << YELLOW"" << getErrorMsg() << ": " << e.what() << NC"" << std::endl;
	}
}

void	AForm::checkExecute(Bureaucrat& executor) const
{
	if (!_sign)
		throw NotSignedForm();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

void    AForm::checkGrades(short int grade)
{
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

/* Exceptions */
const char* AForm::GradeTooHighException::what() const throw() {
    return ("The highest possible grade is 1!!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("The grade it's too low!!");
}

const char* AForm::NotSignedForm::what() const throw() {
	return ("The form it's not signed!!");
}

/* insertion operator overload */
std::ostream& operator<<(std::ostream& out, const AForm* Aform)
{
	out << "[AFORM]\nName: " << Aform->getName() << \
	"\nExecution grade: " << Aform->getExecGrade() \
	<< "\nSign grade: " << Aform->getSignGrade() << std::endl;
	if (Aform->getSign()) {
		out << "Signed: YES" << std::endl;
	} else {
		out << "Signed: NO" << std::endl;
	}
	return (out);
}