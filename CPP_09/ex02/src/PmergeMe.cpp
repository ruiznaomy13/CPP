/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by ncastell          #+#    #+#             */
/*   Updated: 2025/03/21 18:16:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
 	if (ac < 2 || !Parser(av + 1))
		Error("Invalid arguments.");
}

PmergeMe::~PmergeMe() { }

void	PmergeMe::Init()
{
	showContent();
	Sort(numsVec, 1);
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

void	PmergeMe::Sort(std::vector<int> &seq, size_t level)
{
	size_t 	pair_size = pow(2, level);
	size_t	n_pairs = seq.size() / pair_size;

	std::cout << "pairs -> " << n_pairs << "\nseq size = " <<  seq.size() << std::endl;
	if (n_pairs == 1)
		return ;	
	for(size_t i = 0; i < seq.size() - (seq.size() % pair_size); i += pair_size)
	{
		std::vector<int> left(seq.begin() + i, seq.begin() + i + (pair_size / 2));
		std::vector<int> right(seq.begin() + i + (pair_size / 2), seq.begin() + i + pair_size);
		std::cout << "----- iteration: " << level << "------ \nleft: " << left[0] << "\nrigth: " << right[0] << '\n';
	}
	Sort(seq, level + 1);
}

