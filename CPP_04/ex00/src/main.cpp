/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 13:42:48 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Animal.hpp"
#include "../hdr/Cat.hpp"
#include "../hdr/Dog.hpp"
#include "../hdr/WrongAnimal.hpp"
#include "../hdr/WrongCat.hpp"

int main(void)
{
	std::cout << "\n --------------- GOOD POLIMORPHISM -----------------" << std::endl;
	const Animal*	animal1 = new Animal();
	const Animal*	cat1 = new Cat();
	const Animal*	dog1 = new Dog();

	animal1->makeSound();
	cat1->makeSound();
	dog1->makeSound();
	std::cout << "--------->> " << animal1->getType() << std::endl;
	std::cout << "--------->> " << cat1->getType() << std::endl;
	std::cout << "--------->> " << dog1->getType() << std::endl;

	delete cat1;
	delete dog1;
	delete animal1;

	std::cout << "\n\n --------------- WRONG POLIMORPHISM -----------------" << std::endl;
	const WrongAnimal*	wrong_animal1 = new WrongAnimal();
	const WrongAnimal*	wrong_cat1 = new WrongCat();

	wrong_animal1->makeSound();
	wrong_cat1->makeSound();
	std::cout << "--------->> " << wrong_animal1->getType() << std::endl;
	std::cout << "--------->> " << wrong_cat1->getType() << std::endl;
	
	delete wrong_cat1;
	delete wrong_animal1;
}
