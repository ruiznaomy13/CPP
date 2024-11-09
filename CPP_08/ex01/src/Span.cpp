/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:57:39 by ncastell          #+#    #+#             */
/*   Updated: 2024/11/09 17:12:53 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() { }

void Span::addNumber(int num)
{
	if (this->_store.size() >= _N)
		throw std::overflow_error("Span is already full");
	this->_store.push_back(num);
}

unsigned int	Span::longestSpan()
{
	if (this->_store.size() < 2)
		throw std::runtime_error("Not enough elements to calculate the span.");

	std::vector<int> sorted = this->_store;
	std::sort(sorted.begin(), sorted.end());
	unsigned int maxSpan = sorted.back() - sorted.front();

	return (maxSpan);
}


unsigned int	Span::shortestSpan()
{
	if (this->_store.size() < 2)
		throw std::runtime_error("Not enough elements to calculate the span.");

	std::vector<int> sorted = this->_store;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}

	return (minSpan);
}

