/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:57:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/15 17:28:11 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#define	MIN_SIGN_SCF 145
#define	MIN_EXEC_SCF 137

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string    _target;

		void	draw_trees(std::ofstream& outfile) const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void		executeImplement( void ) const;
		std::string	getErrorMsg( void ) const;
};

#endif