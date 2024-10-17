/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:50:09 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/17 13:54:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Uso: " << argv[0] << " <cadena>" << std::endl;
        return 1; // Salir si no se proporciona argumento
    }

    std::string input = argv[1]; // Obtener el argumento de la línea de comandos

    // castAndDisplay(input);
	std::cout << argv[1] << std::endl;

    return 0;
}