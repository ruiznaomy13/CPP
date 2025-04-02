/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by ncastell          #+#    #+#             */
/*   Updated: 2025/03/24 21:26:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	Parser(ac, av + 1);
}

PmergeMe::~PmergeMe() { }

void	PmergeMe::Init()
{
	ShowContent(this->numsVec);
	Sort(numsVec, 1);
	ShowContent(this->numsVec);
}

void	PmergeMe::Parser(int ac, char **av)
{
	int i = 0;

	if (ac < 2)
		return (Error("USAGE: ./PmergeMe <nums>"));
	while (av[i])
	{
		char *end;
		int num = std::strtol(av[i], &end, 10);

		if (*end != '\0' || num < 0 || num < INT_MIN  || num > INT_MAX)
			return (Error("ERROR: Invalid arguments"));
		if (std::find(numsVec.begin(), numsVec.end(), num) != numsVec.end())
			return (Error("ERROR: Repeated numbers in the sequence"));
		numsVec.push_back(num);
		i++;
	}
}

void	PmergeMe::Error(const std::string& errorMsg)
{
	std::cerr << RED"\n\t" << errorMsg << "\n" << std::endl;
	exit(EXIT_FAILURE);
}

void	PmergeMe::ShowContent(std::vector<int> v)
{
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << v[i];
	}
	std::cout << "]\n";
}

void	PmergeMe::Sort(std::vector<int> &seq, size_t level)
{
	size_t pair_size = pow(2, level);
	size_t n_pairs = seq.size() / pair_size;

	/*BORRAR*/
	std::cout << "\n----- Iteration: " << level << "------\n";
	std::cout << "\npairs ->\t" << n_pairs << "\nseq size ->\t" << seq.size() << "\npair size ->\t" << pair_size<< "\n" << std::endl;

	if (n_pairs < 1)
		return;	

	std::vector<int> sortedSeq = seq;

	for (size_t i = 0; i < seq.size() - (seq.size() % pair_size); i += pair_size)
	{
		std::vector<int> left(seq.begin() + i, seq.begin() + i + (pair_size / 2));
		std::vector<int> right(seq.begin() + i + (pair_size / 2), seq.begin() + i + pair_size);

		/* BORRAR */
		size_t lastIndex = (pair_size / 2) - 1;
		std::cout << GREEN"LEFT: " << lastIndex << " -> " << left[lastIndex] << NC << std::endl;
		std::cout << GREEN"RIGHT: " << lastIndex << " -> " << right[lastIndex] << NC << std::endl;

		if (left[lastIndex] > right[lastIndex])
			std::swap_ranges(left.begin(), left.end(), right.begin());

		std::copy(left.begin(), left.end(), sortedSeq.begin() + i);
		std::copy(right.begin(), right.end(), sortedSeq.begin() + i + (pair_size / 2));

		/*BORRA*/
		std::cout << "Left: "; 
		ShowContent(left);
		std::cout << "Right: "; 
		ShowContent(right);
		std::cout << "\n"; 
	}

	Sort(sortedSeq, level + 1);
	seq = sortedSeq;
	
	/* TODO */
	void	Merge(std::vector<int> &seq, size_t level);
}



