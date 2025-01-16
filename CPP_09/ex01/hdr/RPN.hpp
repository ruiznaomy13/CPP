/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:37:46 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/16 13:13:39 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int>	operation_stack;

		bool	is_operator(std::string sign);
		bool	check_num(std::string	str_num);
		int		return_num();

	public:
		RPN();
		~RPN();

		int		calculator(std::string operation);
		void	solve(int a, int b, char op);
};
