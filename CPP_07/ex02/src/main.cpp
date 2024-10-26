/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:30:51 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/26 12:47:28 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

void testInt()
{
    std::cout << "\n==============================INTEGER===============================" << NC "" << std::endl;
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

void testString()
{
    std::cout << "\n===============================STRING===============================" << NC "" << std::endl;
    std::cout << WHITE"\n=== Test 1: Constructor with std::string ===" << NC "" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    std::cout << "Size of strArray: " << strArray.size() << std::endl;
    for (unsigned int i = 0; i < strArray.size(); ++i) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl; // Should print Hello, World, !
    }

    // Test copy constructor for std::string
    Array<std::string> strArrayCopy(strArray);
    std::cout << WHITE"\n=== Test 2: Copy constructor with std::string ===" << NC "" << std::endl;
    std::cout << "Size of strArrayCopy: " << strArrayCopy.size() << std::endl;
    strArrayCopy[0] = "Changed";
    std::cout << "Modified strArrayCopy[0] = " << strArrayCopy[0] << std::endl;
    std::cout << "Original strArray[0] = " << strArray[0] << std::endl; // Should still print "Hello"

    // Test assignment operator with std::string
    Array<std::string> strArrayAssign;
    strArrayAssign = strArray; // Using the assignment operator
    std::cout << WHITE"\n=== Test 3: Assignment operator with std::string ===" << NC "" << std::endl;
    std::cout << "Size of strArrayAssign: " << strArrayAssign.size() << std::endl;
    strArrayAssign[1] = "Everyone";
    std::cout << "Modified strArrayAssign[1] = " << strArrayAssign[1] << std::endl;
    std::cout << "Original strArray[1] = " << strArray[1] << std::endl; // Should still print "World"
}

int main( void )
{
    testInt();
    testString();

    return (0);
}

