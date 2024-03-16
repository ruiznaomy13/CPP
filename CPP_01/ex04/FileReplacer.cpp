/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:34:36 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/16 00:57:03 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& _filename) : filename(_filename)
{}

void	FileReplacer::readFromFile()
{
	std::ifstream				inputFile(filename);
	std::string					line;

	if (!inputFile)
	{
		std::cout << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}

	while (inputFile >> line)
		this->content.push_back(line);
	muestra_vector();
}

void FileReplacer::muestra_vector()
{
	std::vector<std::string>::const_iterator it;

	for (it = this->content.begin(); it != this->content.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;
}