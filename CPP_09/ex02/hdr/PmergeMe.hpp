/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:14:15 by ncastell          #+#    #+#             */
/*   Updated: 2025/02/03 14:16:52 by ncastell         ###   ########.fr       */
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
		std::vector<int>	vec;
		std::deque<int>		dque;
		int					c_size;
		char				**argv;
		double				vec_secs;
		double				dque_secs;
		clock_t				start;
		clock_t				end;

	public:
		PmergeMe(int _c_size, char **_argv);
		~PmergeMe();

		void run();
		void printData() const;
		void printTime() const;

	private:
		void validateInput(const std::string &str);
		int  stringToInt(const std::string &str);
		void parse_argv();
		void measureSortingTime();

		template <typename T>
		void mergeInsertionSort(T &container);
};

#endif
