/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:11:33 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/21 18:39:38 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		std::string	_level;

	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		void	error(void);
		void	warning(void);
		void	info(void);
		void	debug(void);
};

#endif