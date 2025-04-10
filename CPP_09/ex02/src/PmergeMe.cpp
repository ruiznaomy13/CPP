/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/10 02:04:50 by ncastell         ###   ########.fr       */
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
	size_t	pair_size = pow(2, level);
	size_t	element_size = pair_size / 2;
	size_t	n_pairs = seq.size() / pair_size;

	if (n_pairs < 1)
		return;	

	/*BORRAR*/
	std::cout << "\n----- Iteration: " << level << "------\n";
	std::cout << "\npairs ->\t" << n_pairs << "\nseq size ->\t" << seq.size() \
	<< "\npair size ->\t" << pair_size<< "\n" << std::endl;

	for (size_t i = 0; i < seq.size() - (seq.size() % pair_size); i += pair_size)
	{
		std::vector<int> left(seq.begin() + i, seq.begin() + i + element_size);
		std::vector<int> right(seq.begin() + i + element_size, seq.begin() + i + pair_size);

		/* BORRAR */
		size_t lastIndex = element_size - 1;
		std::cout << GREEN"LEFT: " << lastIndex << " -> " << left[lastIndex] << NC << std::endl;
		std::cout << GREEN"RIGHT: " << lastIndex << " -> " << right[lastIndex] << NC << std::endl;

		if (left[lastIndex] > right[lastIndex])
			std::swap_ranges(left.begin(), left.end(), right.begin());

		std::copy(left.begin(), left.end(), seq.begin() + i);
		std::copy(right.begin(), right.end(), seq.begin() + i + element_size);

		/*BORRA*/
		ShowContent("left",left);
		ShowContent("right", right);
		std::cout << "\n"; 
	}

	std::cout << "\n----- End Iteration: " << level << "------\n";
	// ShowContent("seq", seq);
	Sort(seq, level + 1);
	std::cout << "\n----- Iteration: " << level << "------\n";
	ShowContent("seq", seq);
	Merge(seq, pair_size);
}

/*
size_t	PmergeMe::BinarySearch(std::vector<int> vec, size_t start, size_t end, int n, size_t element_size)
{
	std::vector<int> aux;
	for (size_t i = 0; i + element_size < end; i += element_size)
	{
		std::vector<int> n(vec.begin() + i, vec.begin() + i + element_size);
		aux.push_back(n[element_size - 1]);
	}

	while (end >= start)
	{
		int	mid = start + (end - start) / 2;
		// std::cout << "END = " << end << "\nSTART = " << start << "\nMID = " << mid << std::endl;
		std::cout << "MID = " << mid << std::endl;
		if (start >= end)
		{
			if (vec[mid] < n)
				return (mid + 1);
			return (mid);
		}
		if (vec[mid] > n)
			end = mid - 1;
		else if (vec[mid] < n)
			start = mid + 1;
	}

	return (-1);
}*/

size_t PmergeMe::BinarySearch(const std::vector<int>& keys, int target)
{
	size_t	start = 0;
	size_t	end = keys.size();

	while (start < end)
	{
		size_t mid = start + (end - start) / 2;

		if (keys[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}

	return (start);
}

// MAIN: b1, a1, a2, an...
// PEND: b2, b3, bn...
// No-p: %2 != 
void PmergeMe::Merge(std::vector<int> &seq, size_t pair_size)
{
	std::vector<int>	main(seq.begin(), seq.begin() + pair_size);
	std::vector<int>	pend;
	std::vector<int>	non;
	std::vector<int>	aux_nums;
	size_t	i;
	size_t	element_size = pair_size / 2;

	std::cout << "PAIR_SIZE = " << pair_size << "\nELEMENT_SIZE = " << pair_size/2 << std::endl;
	for (i = pair_size; i + element_size <= seq.size(); i += element_size)
	{
		std::vector<int> b(seq.begin() + i, seq.begin() + i + element_size);
		pend.insert(pend.end(), b.begin(), b.end());
		if (i + pair_size > seq.size())
			continue ;
		std::vector<int> a(seq.begin() + i + element_size, seq.begin() + i + pair_size);
		main.insert(main.end(), a.begin(), a.end());
		i += element_size;
	}

	if (i < seq.size())
		non.insert(non.end(), seq.begin() + i, seq.end());

	ShowContent("MAIN", main);
	ShowContent("PEND", pend);
	ShowContent("NON", non);

	for (size_t j = 0; j + element_size <= main.size(); j += element_size)
		aux_nums.push_back(main[j + element_size - 1]);

	for (i = 0; i + element_size <= pend.size(); i += element_size)
	{
		std::vector<int> b(pend.begin() + i, pend.begin() + i + element_size);
		size_t pos = BinarySearch(aux_nums, b[element_size - 1]);

		aux_nums.insert(aux_nums.begin() + pos, b[element_size - 1]);
		main.insert(main.begin() + (pos * element_size), b.begin(), b.end());
		std::cout << RED"POS FOR " << b[element_size - 1] << " = [" << pos << "]" << NC"\n";
	}

	main.insert(main.end(), non.begin(), non.end());
	std::cout << "\n";

	seq = main;
}

size_t	PmergeMe::JacobsthalNum(size_t n)
{
	size_t	aux;

	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	aux = JacobsthalNum(n - 1) + 2 * JacobsthalNum(n - 2);
	return (aux);
}

