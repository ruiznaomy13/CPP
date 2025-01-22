/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:00:51 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/22 16:00:33 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class PmergeMe
{
	private:
		std::vector<int>	arr;

	public:
		PmergeMe();
		~PmergeMe();

		void	mergeInsertionSort(int left, int right);
		void	merge(int left, int mid, int right);
		void	insertionSort(int left, int right);

		// privadas
		void	fill_vector(int argc, char** argv);

		void	print_vector() const; //BORRAR
};

#endif