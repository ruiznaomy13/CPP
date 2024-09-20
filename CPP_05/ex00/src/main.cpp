/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/20 13:31:59 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"

int main( void )
{
    std::cout << "<< BUREAUCRAT TESTING >>" << std::endl;

    // Test constructor with name and grade
    try {
        Bureaucrat B1("Naomy", 5);
        std::cout << B1 << std::endl;

        // Increment grade several times
        B1.incrementGrade();
        B1.incrementGrade();
        B1.incrementGrade();
        B1.incrementGrade();
        std::cout << "After several increments: " << B1 << std::endl;

        // Try to increment beyond limit
        try {
            B1.incrementGrade();  // This should throw GradeTooHighException
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test with grade too high on creation
        try {
            Bureaucrat B2("John", 0);  // Grade too high (0), should throw an exception
        } catch (std::exception& e) {
            std::cout << "Caught exception for B2: " << e.what() << std::endl;
        }

        // Test with grade too low on creation
        try {
            Bureaucrat B3("Doe", 151);  // Grade too low (151), should throw an exception
        } catch (std::exception& e) {
            std::cout << "Caught exception for B3: " << e.what() << std::endl;
        }

        // Test constructor with only grade
        Bureaucrat B4("Carmen", 10);
        std::cout << "B4: " << B4 << std::endl;

        // Test decrementing grade
        B4.decrementGrade();
        std::cout << "After decrementing: " << B4 << std::endl;

        // Test assignment operator
        Bureaucrat B5 = B4;
        std::cout << "B5 (assigned from B4): " << B5 << std::endl;

        // Test copy constructor
        Bureaucrat B6(B1);
        // Bureaucrat B7("Nebucon", 156);
        std::cout << "B6 (copy of B1): " << B6 << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}