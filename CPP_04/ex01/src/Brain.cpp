/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:46:43 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/14 00:36:38 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/Brain.hpp"

Brain::Brain() { std::cout << "[Brain] Created" << std::endl; }

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "[Brain] Assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

void	Brain::setIdea(int pos_idea, std::string idea)
{
	if (pos_idea >= 0 && pos_idea < 100)
		_ideas[pos_idea] = idea;
	else
		std::cout << "That idea dosn't exist" << std::endl;
}

std::string Brain::getIdea(int pos_idea)
{
	if ((pos_idea >= 0 && pos_idea < 100) && !_ideas[pos_idea].empty())
		return _ideas[pos_idea];
	return "THAT IDEA DOESN'T EXIST";
}

Brain::~Brain() { std::cout << "[Brain] Destroyed" << std::endl; }