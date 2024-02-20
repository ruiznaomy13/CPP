/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:29:23 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 17:59:52 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contact[8];
		int		_contact_number;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	saveContactInfo(void);
		void	showContact(void);
};

#endif