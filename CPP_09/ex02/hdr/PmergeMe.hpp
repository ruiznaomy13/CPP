/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:26:09 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/07 00:54:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

# define RED		"\x1b[1;31m"
# define GREEN		"\x1b[1;32m"
# define YELLOW		"\x1b[1;34m"
# define NC			"\033[0m"


class PmergeMe
{
	private:
		std::vector<int>	numsVec;
		int			contSize;

	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	Init();
		void	ShowContent(std::string name, std::vector<int> v);
		void	Sort(std::vector<int> &seq, size_t level);
		void	Merge(std::vector<int> &seq, size_t pair_size);

	private:
		void	Parser(int ac, char **av);
		// bool	Parser(char **av);
		void	Error(const std::string& errorMsg);
};
