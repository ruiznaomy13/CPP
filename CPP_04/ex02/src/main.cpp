/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 01:49:28 by ncastell         ###   ########.fr       */
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
	// Animal a;
	Dog real_dog;
	Cat real_cat;

	real_dog.getBrain()->setIdea(1, "Me encantaria ir a la pradera");
	real_cat.getBrain()->setIdea(5, "Me encanta la LASAGNA");
	std::cout << CYAN"\nREAL_DOG = " << real_dog.getBrain()->getIdea(1) << std::endl;
	std::cout << BLUE"REAL_CAT = " << real_cat.getBrain()->getIdea(5) << std::endl;

	return (0);
}

