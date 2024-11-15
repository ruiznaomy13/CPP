/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:54:40 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/15 12:23:07 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <deque>


template<class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;

		MutantStack(): std::stack<T>() { }
		~MutantStack() { }

		MutantStack(const std::stack<T>& other): std::stack<T>::stack(other) {	}

		std::stack<T>& operator=(const std::stack<T> & other)
		{
			*this = other;
			return (*this);
		}

		iterator	begin() { return std::stack<T>::c.begin();	}
		iterator	end() { return std::stack<T>::c.end();	}
};
