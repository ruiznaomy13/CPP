/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Methods.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:58:24 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/23 19:56:09 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_HPP
# define METHODS_HPP

#include <iostream>

template <class T>
void swap(T& a, T& b)
{
	T	c = a;
	a = b;
	b = c;
}

template <class T>
T	min(T a, T b)
{
	if (a >= b)
		return (b);
	return (a);
}

template <class T>
T	max(T a, T b)
{
	if (a <= b)
		return (b);
	return (a);
}
#endif