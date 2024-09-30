/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"

int main( void )
{
    std::cout << "<< BUREAUCRAT TESTING >>" << std::endl;

    // Test constructor with name and grade
    try {
        Bureaucrat B1("Naomy", 3);
        std::cout << GREEN"" << B1 << NC"" << std::endl;

        // Increment grade several times
        B1.incrementGrade();
        B1.incrementGrade();
        std::cout << GREEN"After several increments B1: " << B1 << NC"" << std::endl;

        // Try to increment beyond limit
        try {
            B1.incrementGrade();
        } catch (std::exception& e) {
            std::cout << YELLOW"Caught exception: " << e.what() << NC"" << std::endl;
        }

        // Test with grade too high
        try {
            Bureaucrat B2("John", 0);
        } catch (std::exception& e) {
            std::cout << YELLOW"Caught exception for B2: " << e.what() << NC"" << std::endl;
        }

        // Test with grade too low
        try {
            Bureaucrat B3("Doe", 151);
        } catch (std::exception& e) {
            std::cout << YELLOW"Caught exception for B3: " << e.what() << NC"" << std::endl;
        }

        // Test constructor with only grade
        Bureaucrat B4("Carmen", 10);
        std::cout << GREEN"B4: " << B4 << NC"" << std::endl;

        // Test decrementing grade
        B4.decrementGrade();
        std::cout << GREEN"After decrementing: " << B4 << NC"" << std::endl;

        // Test assignment operator
        Bureaucrat B5 = B4;
        std::cout << GREEN"B5 (assigned from B4): " << B5 << NC"" << std::endl;

        // Test copy constructor
        Bureaucrat B6(B1);
        std::cout << GREEN"B6 (copy of B1): " << B6 << NC"" << std::endl;
        
    } catch (std::exception& e) {
        std::cout << YELLOW"Caught exception: " << e.what() << NC"" << std::endl;
    }

    return 0;
}