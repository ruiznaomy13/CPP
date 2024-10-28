/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:59:10 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/28 15:55:42 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void	iter(T *array, int len, void (*fun)(T&))
{
	for (int i = 0; i < len; ++i)
	fun(array[i]);
}

#endif