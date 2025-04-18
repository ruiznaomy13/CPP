/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:26:09 by ncastell          #+#    #+#             */
/*   Updated: 2025/03/15 01:47:23 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cstdlib>

# define RED		"\x1b[1;31m"
# define GREEN		"\x1b[1;32m"
# define YELLOW		"\x1b[1;34m"
# define NC			"\033[0m"


class PmergeMe
{
	private:
		std::vector<int>	numsVec;
		int					contSize;

	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	Init();
		void	showContent(void);
		void	merge(void);

	private:
		bool	Parser(char **av);
		void	Error(const std::string& errorMsg);
};