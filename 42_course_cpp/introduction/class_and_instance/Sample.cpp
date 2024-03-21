/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SampleClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 03:51:47 by ncastell          #+#    #+#             */
/*   Updated: 2024/01/13 03:58:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

Sample::Sample(void) {
  std::cout << "Constructor called" << std::endl;
  return ;
}

Sample::~Sample(void) {
  std::cout << "Destructor called" << std::endl;
  return ;
}
