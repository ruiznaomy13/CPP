/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:59:12 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/24 13:10:31 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void printInt(int& element) {
	std::cout << element << " ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5}; // Integer array

	// Create an Iter object with the array and a function to apply to each element
	iter(arr, 5, printInt);

	return 0;
}