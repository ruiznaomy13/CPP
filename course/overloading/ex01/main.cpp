/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:49:15 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/14 17:28:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Example
{
	float x, y;

	Example(float x, float y)
		: x(x), y(y) {}
		
	Example Add(const Example& other) const
	{
		return Example(x + other.x, y + other.y);
	}

	Example Multiply(const Example& other) const
	{
		return Example(x * other.x, y * other.y);
	}
	
	Example operator+(const Example& other) const
	{
		return Add(other);
	}

	Example operator*(const Example& other) const
	{
		return Multiply(other);
	}
};


int main()
{
	Example position(4.0f, 4.0f);
	Example speed(0.5f, 1.5f);
	Example powerup(1.1f, 1.1f);

	Example result1 = position.Add(speed.Multiply(powerup));
	Example result2 = position + speed * powerup;

	std::cout << "Result 1 = x:" << result1.x << " y:1"<< result1.y <<std::endl;
    std::cout << "Result 2 = " << result2.x << std::endl;
}