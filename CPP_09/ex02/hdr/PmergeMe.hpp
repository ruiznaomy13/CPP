/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:26:09 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/24 15:08:18 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <deque>
# include <climits>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <ctime>
# include <iomanip>

# define RED		"\x1b[1;31m"
# define GREEN		"\x1b[1;32m"
# define YELLOW		"\x1b[1;34m"
# define NC			"\033[0m"

#define	MAX_JC	14

class PmergeMe
{
	private:
		std::vector<int>	numsVec_;
		std::vector<int>	auxMainV_;
		double				vecTime_;

		std::deque<int>		numsDeq_;
		
		size_t				inserted;
		std::vector<int>	test;
		int					contSize_;

	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void	Init();
		void	ShowContent(std::string name, std::vector<int> v);
		void	Merge(std::vector<int> &seq, size_t pair_size);
		void	Sort(std::vector<int> &seq, size_t level);
		void	Insertion(std::vector<int> &main, std::vector<int> &pend,
				size_t i, size_t element_size);
		size_t	JacobsthalNum(size_t n);

	private:
		void	Parser(int ac, char **av);
		size_t	BinarySearch(const std::vector<int>& values, size_t end, int target);
		// bool	Parser(char **av);
		void	Error(const std::string& errorMsg);
};
