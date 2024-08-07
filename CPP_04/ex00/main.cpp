/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:42 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/07 13:40:32 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Animal  animal1;
    Cat     cat1;
    Dog     dog1;

    std::cout << "--------->> " << animal1.getType() << std::endl;
    std::cout << "--------->> " << cat1.getType() << std::endl;
    std::cout << "--------->> " << dog1.getType() << std::endl;
}