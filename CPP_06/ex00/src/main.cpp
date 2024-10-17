/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:34:41 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/17 15:37:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Bad number of argument:\n ./scalarConvert <string>" << std::endl;
        return (EXIT_FAILURE);
    }

    ScalarConverter::convert(av[1]);
}