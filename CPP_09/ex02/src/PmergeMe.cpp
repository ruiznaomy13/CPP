/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/07 02:56:16 by ncastell         ###   ########.fr       */
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
	ShowContent("Inicio", this->numsVec);
	Sort(numsVec, 1);
	ShowContent("Fin", this->numsVec);
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

void	PmergeMe::ShowContent(std::string name, std::vector<int> v)
{
	std::cout << name << " = [";
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

	if (n_pairs < 1)
		return;	

	/*BORRAR*/
	std::cout << "\n----- Iteration: " << level << "------\n";
	std::cout << "\npairs ->\t" << n_pairs << "\nseq size ->\t" << seq.size() \
	<< "\npair size ->\t" << pair_size<< "\n" << std::endl;

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

		std::copy(left.begin(), left.end(), seq.begin() + i);
		std::copy(right.begin(), right.end(), seq.begin() + i + (pair_size / 2));

		/*BORRA*/
		ShowContent("left",left);
		ShowContent("right", right);
		std::cout << "\n"; 
	}

	std::cout << "\n----- End Iteration: " << level << "------\n";
	// ShowContent("seq", seq);
	Sort(seq, level + 1);
	Merge(seq, pair_size);
	std::cout << "\n----- Iteration: " << level << "------\n";
}

// MAIN: b1, a1, a2, an...
// PEND: b2, b3, bn...
// No-p: %2 != 
void PmergeMe::Merge(std::vector<int> &seq, size_t pair_size)
{
	std::vector<int> main(seq.begin(), seq.begin() + pair_size);
	std::vector<int> pend;
	std::vector<int> non;
	size_t			i;
	size_t			j;

	std::cout << "PAIR_SIZE = " << pair_size << "\nELEMENT_SIZE = " << pair_size/2 << std::endl;
	for (i = pair_size; i + (pair_size / 2) <= seq.size(); i += pair_size / 2)
	{
		std::vector<int> b(seq.begin() + i, seq.begin() + i + (pair_size / 2));
		pend.insert(pend.end(), b.begin(), b.end());
		if (i + pair_size > seq.size())
			continue ;
		std::vector<int> a(seq.begin() + i + (pair_size / 2), seq.begin() + i + pair_size);
		main.insert(main.end(), a.begin(), a.end());
		i += pair_size/2;
	}

	if (i < seq.size())
		non.insert(non.end(), seq.begin() + i, seq.end());

	// binary_insertion
	size_t lastIndex = (pair_size / 2) - 1;
	for (i = 0; i < pend.size(); i += pair_size/2)
	{
		std::vector<int> b(pend.begin() + i, pend.begin() + i + (pair_size / 2));
		for (j = 0; j < main.size(); j += pair_size / 2)
		{
			std::vector<int> a(main.begin() + j, main.begin() + j + (pair_size / 2));
			if (b[lastIndex] < a[lastIndex])
			{
				main.insert(main.begin() + j, b.begin(), b.end());
				break;
			}
		}
		if (j == main.size())
			main.insert(main.end(), b.begin(), b.end());
	}
	
	/*BORRAR*/
	ShowContent("MAIN", main);
	ShowContent("PEND", pend);
	ShowContent("NON", non);

	main.insert(main.end(), non.begin(), non.end());
	std::cout << "\n";

	seq = main;
}

/*
void	PmergeMe::MergeInsertion(std::vector<int> &seq, size_t pair_size)
{
	// a1, b1, a2, a3, an...
	std::vector<int>	main(seq.begin(), seq.begin() + pair_size);
	std::vector<int> 	pend;

	for (size_t i = pair_size; i < seq.size(); i += pair_size)
	{
		std::vector<int> b(seq.begin() + i, seq.begin() + i + (pair_size / 2));
		pend.insert(pend.end(), b.begin(), b.end());
		if (i + pair_size > seq.size())
			break;
		std::vector<int> a(seq.begin() + i + (pair_size / 2), seq.begin() + i + pair_size);
		main.insert(main.end(), a.begin(), a.end());
	}
	std::vector<int> last;
	ShowContent("MAIN", main);
	ShowContent("PEND", pend);
	ShowContent("seq", seq);
	main.insert(main.end(), last.begin(), last.end());
	seq = main;
}*/


