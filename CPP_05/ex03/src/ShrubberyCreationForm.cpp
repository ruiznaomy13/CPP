/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:17:12 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:11 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
AForm("<target> Presidential Pardon Form", MIN_SIGN_SCF, MIN_EXEC_SCF)
{
	std::cout << BLUE"[ShrubberyCreationForm] Constructor called" << NC"" << std::endl;
	_target = "<target>";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
AForm(target + " Presidential Pardon Form", MIN_SIGN_SCF, MIN_EXEC_SCF)
{
	std::cout << BLUE"[ShrubberyCreationForm] Constructor called" << NC"" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << BLUE"[ShrubberyCreationForm] Copy constructor called" << NC"" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	std::cout << BLUE"[ShrubberyCreationForm] Assignment operator called" << NC"" << std::endl;
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED"[ShrubberyCreationForm] Destructor called for " << \
	this->_target << NC"" << std::endl;
}

void	ShrubberyCreationForm::draw_trees(std::ofstream& outfile) const
{
	outfile << GREEN"                                                   \n";
	outfile << "       ###              ###              ###       \n";
	outfile << "      #o###            #o###            #o###      \n";
	outfile << "    #####o###        #####o###        #####o###    \n";
	outfile << "   #o###|#/###      #o###|#/###      #o###|#/###   \n";
	outfile << "    ####|/#o#        ####|/#o#       #o###|#/###   \n";
	outfile << YELLOW"       }|{              }|{              }|{       \n";
	outfile << YELLOW"       }|{              }|{              }|{       \n";
	outfile << NC"                                                   \n";
}

void ShrubberyCreationForm::executeImplement( void ) const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (outfile.is_open())
	{
		draw_trees(outfile);
		draw_trees(outfile);
		draw_trees(outfile);
		outfile.close();
		std::cout << GREEN"File '" << _target << "_shrubbery' created!" << NC"" << std::endl;
	}
	else
	{
		std::cout << YELLOW"Failed to create the file." << NC"" << std::endl;
	}
}


std::string ShrubberyCreationForm::getErrorMsg( void ) const {
	return (_target + " no trees :( ");
}