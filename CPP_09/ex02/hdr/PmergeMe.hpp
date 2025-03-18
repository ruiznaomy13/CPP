/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:14:15 by ncastell          #+#    #+#             */
/*   Updated: 2025/02/24 16:34:54 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	vec_cont;
		std::deque<int>		dque_cont;
		size_t				c_size;
		char				**argv;

	public:
		PmergeMe(int _c_size, char **_argv);
		~PmergeMe();

	private:
		void	saveNums();
};

#endif
