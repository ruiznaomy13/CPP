/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:29:23 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/05 20:50:50 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

# define MAX_CONTACTS	8

class PhoneBook
{
	private:
		Contact	_contact[MAX_CONTACTS];
		int		_contactNumber;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	saveContactInfo(void);
		void	showContact(int index);
		void	selectAction(std::string action);
		void	errorMsg(int error);
		void	successMsg(int type);
		void	searchContact(void);
		int		isNum(std::string str);
};

#endif