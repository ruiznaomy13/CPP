/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:45:34 by ncastell          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:22 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

# define GREEN		"\x1b[1;32m"
# define NC			"\033[0m"

typedef struct Data
{
	std::string	data;
	int			num;
}				Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other); // Copy constructor
		Serializer& operator=(const Serializer& other); // Assignment operator
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif