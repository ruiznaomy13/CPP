/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:17:02 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/07 13:40:10 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#define	MIN_SIGN_PPF 25
#define	MIN_EXEC_PPF 5

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		void		executeImplement(Bureaucrat& executor) const;
		std::string	getErrorMsg( void ) const;
};

#endif