/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cercle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:25:19 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/16 19:28:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CERCLE_HPP
# define CERCLE_HPP
# include <iostream>

using namespace std;

class Cercle {
  private:
    int radio;

  public:
    Cercle(int);
    float perimeter();
    float area();
};

#endif