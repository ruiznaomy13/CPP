/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:59:12 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/28 15:55:09 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	printInt(int& element) {
	std::cout << element << " ";
}

void	multiply_size(int& element) {
	element = element * element;
}

void	print_mayus(char& element) {
	std::cout << static_cast<char>(std::toupper(element));
}

void	print_lower(char& element) {
	std::cout << static_cast<char>(std::tolower(element));
}


int	main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "\n-------------- INT TEST --------------" << std::endl;
	iter(arr, 9, printInt);
	iter(arr, 9, multiply_size);
	std::cout << "\n";
	iter(arr, 9, printInt);

	std::cout << "\n\n-------------- CHAR TEST --------------" << std::endl;
	char	char_arr[] = "Hola mi gente latino";
	iter(char_arr, 20, print_mayus);
	std::cout << "\n";
	iter(char_arr, 20, print_lower);
	std::cout << "\n" << std::endl;

	return 0;
}