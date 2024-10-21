/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Methods.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:11:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 23:09:53 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Methods.hpp"

Base* generate()
{
    static bool isSeeded = false;

    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(0)));
        isSeeded = true;
    }
    int randomNumber = rand() % 3;

    if (randomNumber == 0)
        return new A();
    else if (randomNumber == 1)
        return new B();
    else
        return new C();
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN"*Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BLUE"*Clas B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << YELLOW"*Class C" << std::endl;
	else
		std::cout << RED"<Unknown type>" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN"&Class A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << BLUE"&Class B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << YELLOW"&Class C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}
