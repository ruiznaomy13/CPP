/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:30:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/26 12:31:54 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

# define RED            "\x1b[31m"
# define GREEN          "\x1b[32m"
# define YELLOW         "\x1b[33m"
# define BLUE           "\x1b[34m"
# define WHITE          "\x1b[1;37m"
# define NC                     "\033[0m"

template <class T>
class Array {
public:
    Array();  // Constructor por defecto
    Array(unsigned int n);  // Constructor con tamaño
    Array(const Array& other);  // Constructor de copia
    Array& operator=(const Array& other);  // Operador de asignación
    T& operator[](int n);  // Operador de subíndice
    ~Array();  // Destructor

    unsigned int size();  // Devuelve el tamaño del array

private:
    T* m_array;  // Puntero al array de elementos
    unsigned int m_size;  // Tamaño del array (número de elementos)
};

// Incluye el archivo de implementación
#include "Array.tpp"

#endif


