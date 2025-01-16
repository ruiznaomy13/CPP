/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:07:39 by ncastell          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:59 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool	RPN::is_operator(std::string sign)
{
	if (sign.size() > 1)
		throw std::runtime_error("ERROR: Bad operation.");
	if (sign[0] == '*' || sign[0] == '/' || sign[0] == '+' || sign[0] == '-')
		return (true);
	return (false);
}

bool	RPN::check_num(std::string str_num)
{
	for (size_t i = 0; i < str_num.size(); i++)
	{
		if (!isdigit(str_num[i]))
			return (false);
	}
	return (true);
}

void	RPN::solve(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			operation_stack.push(a + b); break;
		case '-':
			operation_stack.push(a - b); break;
		case '*':
			operation_stack.push(a * b); break;
		case '/': 
			if (b == 0)
				throw std::runtime_error("ERROR: Division by zero.");
			operation_stack.push(a / b); break;
	}
}

int	RPN::return_num()
{
	int	top_num = -1;

	if (operation_stack.empty())
		throw std::runtime_error("ERROR: Bad operation.");
	top_num = operation_stack.top(); operation_stack.pop();
	return (top_num);
}

int	RPN::calculator(std::string operation)
{
	int					num, a, b;
	std::string			tmp;
	std::stringstream	str_strm(operation);
	
	while (str_strm >> tmp)
	{
		try {
			if (check_num(tmp))
			{
				num = std::atoi(tmp.c_str());
				if (num > 9 || num < 0 )
					throw std::runtime_error("ERROR: Bad number.");
				operation_stack.push(num);
			}
			else if (is_operator(tmp))
			{
					b = return_num();
					a = return_num();
					solve(a, b, tmp[0]);
				std::cout << "-> "<<a<<tmp<<b<<"="<<operation_stack.top() << std::endl;
			}
			else 
				throw std::runtime_error("ERROR: Unexpected symbol."); // DUDOSO
		} catch (const std::exception& e) {
			throw std::runtime_error(e.what());
		}
	}
	if (operation_stack.size() > 1)
		throw std::runtime_error("ERROR: Bad operation 1.");
	std::cout << GREEN"RESULT = " << operation_stack.top() << NC"" << std::endl;
	return (0);
}

// int	RPN::calculator(std::string operation)
// {
// 	int	a, b;
	
// 	for (size_t i = 0; i < operation.size(); i++)
// 	{
// 		if (operation[i] != ' ')
// 		{
// 			if (isdigit(operation[i]))
// 			{
// 				operation_stack.push(operation[i] - '0');
// 			}
// 			else if (is_operator(operation[i]))
// 			{
// 				try {
// 					b = return_num();
// 					a = return_num();
// 					solve(a, b, operation[i]);
// 				} catch (const std::exception& e) {
// 					throw std::runtime_error(e.what());
// 				}
// 				std::cout << "-> "<<a<<operation[i]<<b<<"="<<operation_stack.top() << std::endl;
// 			}
// 			else 
// 				throw std::runtime_error("ERROR: Bad operation.");
// 		}
// 	}
// 	if (operation_stack.size() > 1)
// 		throw std::runtime_error("ERROR: Bad operation.");
// 	std::cout << "RESULT = " << operation_stack.top() << std::endl;
// 	return (0);
// }
