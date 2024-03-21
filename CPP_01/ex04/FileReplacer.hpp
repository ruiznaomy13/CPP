/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:33:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/21 17:40:14 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_REPLACER_HPP
# define FILE_REPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

# define ERROR_OF	1


class FileReplacer
{
	private:
		std::string 	filename;
		std::string		file;
		std::string		s1;
		std::string		s2;
		std::string		buffer;
		std::string		text;
		std::ifstream	infile;
		std::ofstream	outfile;

	public:
		FileReplacer(const std::string& _filename);

		void 	readFromFile();
		void	newFileGenerator();
		void	ft_error(int error);

		void	setS1(std::string& _s1);
		void	setS2(std::string& _s2);
};


#endif