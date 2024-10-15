/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:01:43 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/14 18:19:46 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	
	public:
		static void 	convert(std::string strConvert);
};

#endif