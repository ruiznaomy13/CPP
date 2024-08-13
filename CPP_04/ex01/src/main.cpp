/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/13 19:48:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Animal.hpp"
#include "../hdr/Cat.hpp"
#include "../hdr/Dog.hpp"
#include "../hdr/WrongAnimal.hpp"
#include "../hdr/WrongCat.hpp"

#define NUM_ANIMALS	2

int main() {
    Animal* animals[NUM_ANIMALS];

    std::cout << "\nCreating Dogs and Cats" << std::endl;
    for (int i = 0; i < NUM_ANIMALS / 2; ++i) {
        animals[i] = new Dog(); }

    for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i) {
        animals[i] = new Cat(); }

	std::cout << "\n -->> Testing deep copy" << std::endl;
    Dog real_dog;
    Dog copy_dog(real_dog); // Testing copy constructor

    
    std::cout << "\n--------------------------------------" << std::endl;
    copy_dog.setBrainIdeas("Me encantaria ir a la pradera\n", 1);
    std::cout << copy_dog.getBrainIdea(1);
    std::cout << real_dog.getBrainIdea(1);
    
    std::cout << "\n-->> Deleting Animals" << std::endl;
    for (int i = 0; i < NUM_ANIMALS; ++i) {
        delete animals[i]; }

    return (0);
}

