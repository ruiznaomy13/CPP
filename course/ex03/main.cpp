/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:29:25 by ncastell          #+#    #+#             */
/*   Updated: 2024/01/11 17:16:59 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ramen.h"
#include <iostream>

using namespace std;

int main()
{
  int numPersonas = -1;
  int edad = 0;
  int total = 0;

  while (edad != -1)
  {
    total = total + edad;
    numPersonas++;
    cout << "Introduc la edad de la persona " << numPersonas + 1 << " o (-1) para salir" << endl;
    cin >> edad;
  }

  cout << "Media edad " << numPersonas << " = " << (total / numPersonas) << endl; 
}
