/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:30:51 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/28 15:44:04 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

void	testInt()
{
	std::cout << "\n============================= INTEGER ==============================" << NC "" << std::endl;
	std::cout << WHITE "=== Test 1: Default constructor ===" << NC "" << std::endl;
	Array<int> arr1;
	std::cout << "Size of arr1: " << arr1.size() << std::endl;

	std::cout << WHITE "\n=== Test 2: Constructor with size ===" << NC "" << std::endl;
	Array<int> arr2(5);
	std::cout << "Size of arr2: " << arr2.size() << std::endl;
	for (unsigned int i = 0; i < arr2.size(); ++i) {
		std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
	}

	std::cout << WHITE "\n=== Test 3: Copy constructor ===" << NC "" << std::endl;
	Array<int> arr3(arr2); // Copy constructor
	std::cout << "Size of arr3: " << arr3.size() << std::endl;

	arr3[0] = 10;
	std::cout << "Modified arr3[0] = " << arr3[0] << std::endl;
	std::cout << "Original arr2[0] = " << arr2[0] << std::endl;

	std::cout << WHITE "\n=== Test 4: Assignment operator ===" << NC "" << std::endl;
	Array<int> arr4; 
	arr4 = arr2;
	std::cout << "Size of arr4: " << arr4.size() << std::endl;
	arr4[1] = 20;
	std::cout << "Modified arr4[1] = " << arr4[1] << std::endl;
	std::cout << "Original arr2[1] = " << arr2[1] << std::endl;

	std::cout << WHITE "\n=== Test 5: Access out of bounds ===" << NC "" << std::endl;
	try {
		std::cout << arr2[10] << std::endl;
	} catch (const std::exception& e) {
		std::cout << YELLOW "Caught exception: " << e.what() << NC "" << std::endl;
	}

	std::cout << WHITE "\n=== Test 6: Size function ===" << NC "" << std::endl;
	std::cout << "Size of arr2: " << arr2.size() << "\n" << std::endl;
}

void	testString()
{
	std::cout << "\n\n============================ STD::STRING ============================" << NC "" << std::endl;
	std::cout << WHITE"=== Test 1: Constructor ===" << NC "" << std::endl;
	Array<std::string> string_arr(3);
	string_arr[0] = "What's Up";
	string_arr[1] = "People";
	string_arr[2] = "!";

	std::cout << "Size of string_arr: " << string_arr.size() << std::endl;
	for (unsigned int i = 0; i < string_arr.size(); ++i)
		std::cout << "string_arr[" << i << "] = " << string_arr[i] << std::endl;

	Array<std::string> string_copy(string_arr);
	std::cout << WHITE"\n=== Test 2: Copy constructor ===" << NC "" << std::endl;
	std::cout << "Size of string_copy: " << string_copy.size() << std::endl;
	string_copy[0] = "Changed";
	std::cout << "Modified string_copy[0] = " << string_copy[0] << std::endl;
	std::cout << "Original string_arr[0] = " << string_arr[0] << std::endl;

	try {
		std::cout << string_arr[4] << std::endl;
	} catch (const std::exception& e) {
		std::cout << YELLOW "Caught exception: " << e.what() << NC "" << std::endl;
	}

	Array<std::string> string_assign;
	string_assign = string_arr; // Using the assignment operator
	std::cout << WHITE"\n=== Test 3: Assignment operator ===" << NC "" << std::endl;
	std::cout << "Size of string_assign: " << string_assign.size() << std::endl;
	string_assign[1] = "Everyone";
	std::cout << "Modified string_assign[1] = " << string_assign[1] << std::endl;
	std::cout << "Original string_arr[1] = " << string_arr[1] << std::endl; // Should still print "World"
}

int	main( void )
{
	testInt();
	testString();

	return (0);
}

