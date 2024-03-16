/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:33:35 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/16 00:44:03 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_REPLACER_HPP
# define FILE_REPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

class FileReplacer
{
	private:
		std::string 				filename;
		std::vector<std::string>	content;

	public:
		FileReplacer(const std::string& _filename);

		void readFromFile();
		// void replaceString(const std::string& s1, const std::string& s2);
		// void writeToFile();
		void	muestra_vector();
};


#endif