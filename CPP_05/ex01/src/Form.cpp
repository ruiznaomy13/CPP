/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:31:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/01 16:24:58 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Form.hpp"

/* Constructors */
Form::Form() : _name("<<no one>>"), _signGrade(150), _execGrade(150) {
	std::cout << BLUE"[FORM] Constructor called []" << NC"" << std::endl;
}

Form::Form(std::string name) : _name(name), _signGrade(150), _execGrade(150) {
	std::cout << BLUE"[FORM] Constructor called (" << _name << ")" \
	<< NC"" << std::endl;
}

Form::Form(int signGrade, int execGrade) : \
_name("<<no one>>"), _signGrade(signGrade), _execGrade(execGrade) {
	checkGrades(_execGrade);
	checkGrades(_signGrade);
	std::cout << BLUE"[FORM] Constructor called (" << _name << ", " \
	<< _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : \
_name(name), _signGrade(signGrade), _execGrade(execGrade) {
	checkGrades(_execGrade);
	checkGrades(_signGrade);
	std::cout << BLUE"[FORM] Constructor called (" << _name << ", " \
	<< _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

Form::~Form() {
	std::cout << RED"[FORM] " << _name << " Destructor called for " << this->_name << NC"" << std::endl;
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

void    Form::checkGrades(int grade)
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
    return ("The lowest possible grade is 150!!");
}

/* insertion operator overload */
std::ostream& operator<<(std::ostream& out, const Form* form) {
	out << "[FORM]\nName: " << form->getName() << "\nExecution grade: " << form->getExecGrade() \
	<< "\nSign grade: " << form->getSignGrade() << std::endl;
	if (form->getSign()) {
		std::cout << "Sign: YES" << std::endl;
	} else {
		std::cout << "Sign: NO" << std::endl;
	}
	return (out);
}