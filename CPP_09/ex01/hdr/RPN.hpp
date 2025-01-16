/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:37:46 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/16 12:14:03 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	operation_stack;

		bool	is_operator(char c);
		int		return_num();

	public:
		RPN();
		~RPN();

		int		calculator(std::string operation);
		void	solve(int a, int b, char op);
};
