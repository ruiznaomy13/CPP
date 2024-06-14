/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:08:23 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/05 19:15:13 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>


int main()
{
  int base, exponent;

  std::cout << "Base: ";
  std::cin >> base;
  std::cout << "Exponent: ";
  std::cin >> exponent;

  double  power = pow(base, exponent);
  std::cout << power << std::endl;
}
