/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:28:52 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/09 17:14:44 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <numeric>

# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define WHITE	"\x1b[1;37m"
# define NC		"\033[0m"

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_store;

	public:
		Span(unsigned int N);
		~Span();

		void	addNumber(int num);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif