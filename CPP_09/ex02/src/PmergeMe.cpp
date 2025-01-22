/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:01:35 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/22 15:59:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // Inicialización opcional, si es necesario
    std::cout << "PmergeMe creado correctamente." << std::endl;
}

PmergeMe::~PmergeMe() { }

void PmergeMe::print_vector() const
{
    std::cout << "Números en el vector: ";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void	PmergeMe::fill_vector(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i) // Comienza desde 1 para ignorar el nombre del programa
	{
		std::string arg = argv[i]; // Convierte el argumento en std::string

		std::stringstream ss(arg); // Usamos un stringstream para convertirlo
		int num;
		
		// Verifica si la conversión fue exitosa
		if (!(ss >> num)) // Si no pudo convertir el string a un número
		{
			std::cerr << "ERROR: El argumento '" << argv[i] << "' no es un entero válido." << std::endl;
		}
		else
		{
			arr.push_back(num); // Si es válido, lo agregamos al vector
		}
	}
}

void    PmergeMe::insertionSort(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void    PmergeMe::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = arr[left + i];
	for (int i = 0; i < n2; ++i)
		R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = R[j++];
}

void    PmergeMe::mergeInsertionSort(int left, int right)
{
    if (left < right)
	{
		if (right - left + 1 <= 10) // Umbral para usar Insertion Sort
			insertionSort(left, right);
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertionSort(left, mid);
			mergeInsertionSort(mid + 1, right);
			merge(left, mid, right);
		}
	}
}
