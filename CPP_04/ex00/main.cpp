/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/07 16:14:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal  animal1;
	Animal	*cat1 = new Cat();
	Animal	*dog1 = new Dog();

	animal1.makeSound();
	cat1->makeSound();
	dog1->makeSound();
	std::cout << "--------->> " << animal1.getType() << std::endl;
	std::cout << "--------->> " << cat1->getType() << std::endl;
	std::cout << "--------->> " << dog1->getType() << std::endl;
	
	delete cat1;
	delete dog1;
}
