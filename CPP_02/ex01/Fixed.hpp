/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:43:55 by ncastell          #+#    #+#             */
/*   Updated: 2024/04/25 10:50:17 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					num;
		static const int	rawBits = 8;

	public:
		Fixed();
		Fixed(const int _num);
		Fixed(const float _num);
		Fixed(const Fixed& other); // copy constructor
		Fixed& operator = (const class Fixed& other); // copy assignment operator
		~Fixed();

		// getters && setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const; // cosnt: el objeto no es modificado internamente
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
