/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:08:21 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/05 17:51:17 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <exception>

# define GREEN		"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define WHITE		"\x1b[1;37m"
# define NC			"\033[0m"

class	ElementNotFound : public std::exception
{
	public:
		const char*	what() const throw() {
			return ("Element not found!");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return (it);
	throw ElementNotFound();
}

#endif