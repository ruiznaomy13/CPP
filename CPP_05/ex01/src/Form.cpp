/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:31:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/30 17:51:13 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Form.hpp"

/* Constructors */
Form::Form() : _name("<<no one>>"), _signGrade(150), _execGrade(150) {
    std::cout << BLUE"[FORM] Constructor called []" << NC"" << std::endl;
}

Form::Form(std::string name) : _name(name), _signGrade(150), _execGrade(150) {
    std::cout << BLUE"[FORM] Constructor called (" << _name << ")" << NC"" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : \
_name(name), _signGrade(signGrade), _execGrade(execGrade) {
    checkGrades(_execGrade);
    checkGrades(_signGrade);
    std::cout << BLUE"[FORM] Constructor called (" << _name << ", " \
    << _signGrade << ", " << _execGrade << ")" << NC"" << std::endl;
}

void    Form::checkGrades(int grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}