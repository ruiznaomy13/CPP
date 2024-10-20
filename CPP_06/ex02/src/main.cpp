/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:06:57 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 22:59:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Methods.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	// Generar instancias de A, B y C
	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();

	std::cout << "\n--- Identificación con puntero ---" << std::endl;
	identify(obj1);
	identify(obj2);
	identify(obj3);

	std::cout << "\n--- Identificación con referencia ---" << std::endl;
	identify(*obj1);
	identify(*obj2);
	identify(*obj3);

	// Limpiar la memoria
	delete obj1;
	delete obj2;
	delete obj3;

	return 0;
}
