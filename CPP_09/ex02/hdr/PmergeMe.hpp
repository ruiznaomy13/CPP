/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:26:09 by ncastell          #+#    #+#             */
/*   Updated: 2025/04/10 01:32:28 by ncastell         ###   ########.fr       */
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

#define	MAX_JC	14

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

		size_t	JacobsthalNum(size_t );
	private:
		void	Parser(int ac, char **av);
		size_t	BinarySearch(const std::vector<int>& values, int target);
		// bool	Parser(char **av);
		void	Error(const std::string& errorMsg);
};
