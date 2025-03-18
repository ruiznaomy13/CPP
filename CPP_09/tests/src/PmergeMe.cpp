/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by ncastell          #+#    #+#             */
/*   Updated: 2025/03/15 02:22:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac < 2 || !Parser(&av[1]))
		Error("Invalid arguments.");
}

PmergeMe::~PmergeMe() { }

void	PmergeMe::Init()
{
	showContent();
}

bool	PmergeMe::Parser(char **av)
{
	int i = 0;

	while (av[i])
	{
		char *end;
		int num = std::strtol(av[i], &end, 10);

		if (*end != '\0' || num < 0)
			return (false);
		numsVec.push_back(num);
		i++;
	}
	return (true);
}

void	PmergeMe::Error(const std::string& errorMsg)
{
	std::cerr << RED"ERROR: " << errorMsg << std::endl;
	exit(EXIT_FAILURE);
}

void	PmergeMe::showContent(void)
{
	std::cout << "[";
	for (size_t i = 0; i < numsVec.size(); i++)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << numsVec[i];
	}
	std::cout << "]\n";
}

void	PmergeMe::merge(void)
{
	// [10, 8, 2, 4, 9, 3, 7, 1, 5] -> [{10, 8}, {2, 4}, {9, 3}, {7, 1}, 5]
	// [{8, 10}, {2, 4}, {3, 9}, {1, 7}, 5] -> [{8, 10, 2, 4}, {3, 9, 2, 7}, 5]
}
