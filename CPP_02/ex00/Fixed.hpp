/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:43:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/04/22 18:28:51 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	raw = 8;

	public:
		Fixed();
		Fixed(const Fixed& other); // copy constructor
		Fixed& operator = (const class Fixed& other); // copy assignment operator
		~Fixed();

		// getters && setters
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
