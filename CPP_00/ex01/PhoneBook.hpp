/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:29:23 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/20 18:44:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contact[3];
		int		_contactNumber;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	saveContactInfo(void);
		void	showContact(int index);
		void	selectAction(std::string action);
		void	errorMsg(int error);
		void	searchContact(void);
		int		isNum(std::string str);
};

#endif