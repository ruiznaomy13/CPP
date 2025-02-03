/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:18:25 by ncastell          #+#    #+#             */
/*   Updated: 2025/02/03 15:36:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int _c_size, char **_argv) : c_size(_c_size - 1),  argv(_argv)
{
	parse_argv();
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateInput(const std::string &str)
{
	if (str.empty())
	{
		std::cerr << "Error: Empty input" << std::endl;
		exit(1);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cerr << "Error: Invalid input: [" << str << "]" << std::endl;
			exit(1);
		}
	}
}

int PmergeMe::stringToInt(const std::string &str)
{
	validateInput(str);
	long num = std::atol(str.c_str());
	if (num > 2147483647) 
	{
		std::cerr << "Error: Number too large: " << str << std::endl;
		exit(1);
	}
	return static_cast<int>(num);
}

void PmergeMe::parse_argv()
{
	for (size_t i = 1; argv[i]; i++)
	{
		int num = stringToInt(argv[i]);
		vec.push_back(num);
		dque.push_back(num);
	}
}

template <typename T>
void PmergeMe::mergeInsertionSort(T &container)
{
	if (container.size() < 2)
		return ;

	std::vector<int> left, right;
	size_t mid = container.size() / 2;

	for (size_t i = 0; i < mid; i++)
		left.push_back(container[i]);
	for (size_t i = mid; i < container.size(); i++)
		right.push_back(container[i]);

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	container.clear();
	size_t i = 0, j = 0;
	while (i < left.size() || j < right.size())
	{
		if (j >= right.size() || (i < left.size() && left[i] < right[j]))
			container.push_back(left[i++]);
		else
			container.push_back(right[j++]);
	}
}

void PmergeMe::measureSortingTime()
{
	start = clock();
	mergeInsertionSort(this->vec);
	end = clock();
	vec_secs = (double)(end - start) / CLOCKS_PER_SEC * 100000.0;

	start = clock();
	mergeInsertionSort(this->dque);
	end = clock();
	dque_secs = (double)(end - start) / CLOCKS_PER_SEC * 100;
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	printData();
	measureSortingTime();
	std::cout << "After: ";
	printData();
	printTime();
}

void PmergeMe::printData() const
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printTime() const
{
	std::cout << "Time to process a range of " << c_size << " elements with std::vector: " << vec_secs << " us" << std::endl;
	std::cout << "Time to process a range of " << c_size << " elements with std::deque: " << dque_secs << " us" << std::endl;
}
