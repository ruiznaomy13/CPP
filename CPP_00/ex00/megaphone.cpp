/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:31:25 by ncastell          #+#    #+#             */
/*   Updated: 2024/01/11 21:29:15 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void megaphone(char **str)
{
  int i = 0;

  while (str[i]) {
    char *currentStr = str[i];
    while (*currentStr) {
      std::cout << (char)std::toupper((unsigned char)*currentStr);
      currentStr++;
    }
    i++;
  }
}

int main(int ac, char **av)
{
  (void)ac;
  megaphone(av);
  std::cout << std::endl;

  return (0);
}
