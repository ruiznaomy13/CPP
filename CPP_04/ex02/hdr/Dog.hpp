/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:31:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 00:22:44 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator = (const Dog& other);
		~Dog();

		Brain*	getBrain( void );

		void	makeSound( void ) const;
};

#endif