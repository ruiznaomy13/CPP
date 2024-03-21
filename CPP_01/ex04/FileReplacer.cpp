/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:34:36 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/21 17:48:06 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& _filename) : filename(_filename)
{}

void	FileReplacer::readFromFile()
{
	infile.open(this->filename);
	if (!this->infile.is_open())
		return (ft_error(ERROR_OF));
	while (std::getline(this->infile, this->buffer))
	{
		this->text += this->buffer;
		this->text += "\n";
	}
	this->infile.close();
}

void	FileReplacer::newFileGenerator()
{
	int	size = this->s1.size();
	int	search = this->text.find(s1, 0);

	outfile.open(this->filename + ".replace");
	if (!this->outfile)
		return (ft_error(ERROR_OF));
	for (int i = 0; this->text[i]; i++)
	{
		if (i == search)
		{
			this->outfile << this->s2;
			i += size - 1;
			search = this->text.find(this->s1, i);
		}
		else
			this->outfile << this->text[i];
	}
	this->outfile.close();
}

void	FileReplacer::ft_error(int error)
{
	if (error == ERROR_OF)
		std::cerr << "Something went wrong opening file" << std::endl;
}

void	FileReplacer::setS1(std::string& _s1)
{
	this->s1 = _s1;
}

void	FileReplacer::setS2(std::string& _s2)
{
	this->s2 = _s2;
}
