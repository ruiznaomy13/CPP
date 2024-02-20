/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:26:20 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/16 19:28:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "Cercle.hpp"

class Rectangle {
  private: //atributes
    int base;
    int height;

  public:
    Rectangle(int,int); //constructor
    int perimeter(); //methods
    int area();

};

#endif