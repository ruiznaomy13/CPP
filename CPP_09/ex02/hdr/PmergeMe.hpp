/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:14:15 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/31 17:20:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int>  dque;
		char           **argv;
		double          vec_secs;
		double          dque_secs;

		// 🔹 Métodos auxiliares
		void validateInput(const std::string &str);
		int  stringToInt(const std::string &str);
		void parse_argv();
		void measureSortingTime();

		// 🔹 Algoritmo de Ford-Johnson
		template <typename T>
		void mergeInsertionSort(T &container);

	public:
		PmergeMe(char **_argv);
		~PmergeMe();

		void run();
		void printData() const;
		void printTime() const;
};

#endif
