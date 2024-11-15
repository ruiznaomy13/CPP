/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:05:31 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/15 12:42:12 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void	myMutantStackTest()
{
	MutantStack<int> mstack;

	std::cout << "________________ MUTANT STACK _______________" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "-->> " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << " = " << mstack.top()<< std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	std::cout << "-->> " << mstack.top() << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "-->> " << s.top() << std::endl;
}

void	listTest()
{
	std::list<int> mstack;

	std::cout << "__________________ LIST _________________" << std::endl;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "-->> " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << " = " << mstack.front()<< std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	std::cout << "-->> " << mstack.back() << std::endl;
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	std::cout << "-->> " << s.back() << std::endl;
}

int main()
{
	myMutantStackTest();
	listTest();
	return 0;
}
