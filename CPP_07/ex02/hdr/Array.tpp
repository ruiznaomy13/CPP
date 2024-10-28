/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:30:46 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/28 15:45:48 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Constructor por defecto
template <typename T>
Array<T>::Array(): m_array(0), m_size(0)
{
	std::cout << BLUE"Default constructor called >> size[0], array[NULL]" << NC"" << std::endl;
}

// Constructor con tamaño
template <typename T>
Array<T>::Array(unsigned int n)
: m_array(new T[n]()), m_size(n)
{
	std::cout << BLUE"Constructor called >> size[" << n << "], array[DEFAULT]" << NC"" << std::endl;
}

// Constructor de copia
template <typename T>
Array<T>::Array(const Array<T>& other)
: m_array(new T[other.m_size]), m_size(other.m_size)
{
	for (unsigned int i = 0; i < m_size; i++)	
		this->m_array[i] = other.m_array[i];
}

// Operador de asignación
template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->m_array;
		this->m_size = other.m_size;
		this->m_array = new T[this->m_size];
		for (unsigned int i = 0; i < m_size; i++)
			this->m_array[i] = other.m_array[i];
	}
	return (*this);
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	std::cout << RED"Destructor called" << NC"" << std::endl;
	delete[] this->m_array;
}

// Operador de subíndice
template <typename T>
T&	Array<T>::operator[](const int n)
{
	if (n < 0 || n >= static_cast<int>(this->m_size))
		throw std::out_of_range("Index out of bounds");
	return (this->m_array[n]);
}

// Tamaño del array
template <typename T>
unsigned int	Array<T>::size()
{
	return (this->m_size);
}
