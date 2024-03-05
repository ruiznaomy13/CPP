/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:45:37 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/05 17:25:44 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <iomanip> 

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define WHITE		"\e[1;37m"
# define CYAN		"\x1b[36m"
# define MAGENTA	"\033[95m"
# define NC			"\033[0m"

class Contact
{
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkSecret;

	public:
		Contact();
		~Contact();
		
		// setters
		void		setFirstName(std::string);
		void		setLastName(std::string);
		void		setNickName(std::string);
		void		setPhoneNumber(std::string);
		void		setDarkSecret(std::string);
		
		// getters
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkSecret(void);

		void		showContact(int index);
		void		showFullContact(void);
};

#endif