/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:07:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/14 16:06:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	msg = "HI THIS IS BRAIN";
	std::string	*stringPTR = &msg;
	std::string	&stringREF = msg;
	
	std::cout << "------- MEMORY ADRESSES -------" << std::endl;
	std::cout << "string    = " << &msg \
	<< "\nstringPTR = " << &stringPTR \
	<< "\nstringREF = " << &stringREF << std::endl;

	std::cout << "\n------------ VALUE ------------" << std::endl;
	std::cout << "string    = " << msg \
	<< "\nstringPTR = " << stringPTR \
	<< "\nstringREF = " << stringREF << std::endl;
}