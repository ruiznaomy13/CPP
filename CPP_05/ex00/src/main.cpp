/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/09/19 16:23:42 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Bureaucrat.hpp"

int main( void )
{
    std::cout << "<< BUREAUCRAT >>" << std::endl;

    Bureaucrat  B1("Naomy", 5);
    std::cout << B1 << std::endl;
    B1.incrementGrade();
    B1.incrementGrade();
    B1.incrementGrade();
    B1.incrementGrade();
    try {
        B1.incrementGrade();
    } catch (std::exception& e)
    {
        std::cout << "Pillado" << std::endl;
    }
    try {
        B1.incrementGrade();
    } catch (std::exception& e)
    {
        std::cout << "Pillado" << std::endl;
    }
    // B1.incrementGrade();
    std::cout << B1 << std::endl;
}