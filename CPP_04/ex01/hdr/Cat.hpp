/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:09:20 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 00:44:07 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator = (const Cat& other);
		~Cat();

		Brain*	getBrain( void );

		void	makeSound( void ) const;
};


#endif