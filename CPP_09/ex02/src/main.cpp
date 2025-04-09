/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:29:31 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/10 01:04:29 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    PmergeMe program(ac, av);

    program.Init();
    //std::cout << "JACOBSTHAL = " << program.JacobsthalNum(std::atoi(av[1])) << std::endl;
}