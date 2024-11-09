/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 224/11/5 15:8:13 by ncastell          #+#    #+#             */
/*   Updated: 224/11/5 17:4:42 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


// Test function
template <typename C>
void testContainer(C& cont, int searchValue)
{
	try {
		typename C::iterator result = easyfind(cont, searchValue);
		std::cout << GREEN"Element found: " << *result << NC"" << std::endl;
	} catch (const ElementNotFound& e) {
		std::cout << YELLOW"" << e.what() << NC"" << std::endl;
	}
}

int main()
{
	std::cout << WHITE"\n============================ VECTOR ==============================" << NC "" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	testContainer(vec, 3);
	testContainer(vec, 6);

	std::cout << WHITE"\n============================= DEQUE ==============================" << NC "" << std::endl;
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	testContainer(deq, 5);
	testContainer(deq, 0);

	std::cout << WHITE"\n============================= LIST ===============================" << NC "" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	testContainer(lst, 4);
	testContainer(lst, -5);

	return (0);
}