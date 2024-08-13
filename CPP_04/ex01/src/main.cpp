/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 01:00:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Animal.hpp"
#include "../hdr/Cat.hpp"
#include "../hdr/Dog.hpp"
#include "../hdr/WrongAnimal.hpp"
#include "../hdr/WrongCat.hpp"

#define NUM_ANIMALS	8

int main()
{
	Animal* animals[NUM_ANIMALS];

	std::cout << GREEN"\n---->> Creating Dogs and Cats <<----" << std::endl;
	for (int i = 0; i < NUM_ANIMALS / 2; ++i) {
		animals[i] = new Dog(); }

	for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i) {
		animals[i] = new Cat(); }

	std::cout << WHITE"\n ------>> Testing deep copy <<------" << std::endl;
	Dog real_dog;
	Cat real_cat;
	Dog copy_dog(real_dog);
	Cat copy_cat(real_cat);
	Dog	copy_dog_2;
	Cat	copy_cat_2;
	copy_dog_2 = copy_dog;
	copy_cat_2 = copy_cat;

	real_dog.getBrain()->setIdea(1, "Me encantaria ir a la pradera");
	copy_dog.getBrain()->setIdea(1, "Yo prefiero ir a la playa, hace calor");
	copy_dog_2.getBrain()->setIdea(1, "YO como que me quedo en casa mejor...");
	std::cout << CYAN"\nREAL_DOG = " << real_dog.getBrain()->getIdea(1) << std::endl;
	std::cout << CYAN"COPY_DOG = " << copy_dog.getBrain()->getIdea(1) << std::endl;
	std::cout << CYAN"COPY_DOG_2 = " << copy_dog_2.getBrain()->getIdea(1) << std::endl;

	real_cat.getBrain()->setIdea(5, "Me encanta la LASAGNA");
	copy_cat.getBrain()->setIdea(5, "Yo prefiero la LECHE");
	copy_cat_2.getBrain()->setIdea(5, "comida es COMIDA ...");
	std::cout << BLUE"REAL_CAT = " << real_cat.getBrain()->getIdea(5) << std::endl;
	std::cout << BLUE"COPY_CAT = " << copy_cat.getBrain()->getIdea(5) << std::endl;
	std::cout << BLUE"COPY_CAT_2 = " << copy_cat_2.getBrain()->getIdea(5) << std::endl;
	
	std::cout << RED"\n------->> Deleting Animals <<-------" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; ++i) {
		delete animals[i]; }
	return (0);
}

