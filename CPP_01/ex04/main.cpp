/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:16:52 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/21 17:47:33 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Use: " << argv[0] << " [file] [str1] [str2]" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string _s1 = argv[2];
	std::string _s2 = argv[3];

	FileReplacer FileReplacer(filename);
	FileReplacer.setS2(_s2);
	FileReplacer.setS1(_s1);
	
	FileReplacer.readFromFile();
	FileReplacer.newFileGenerator();
}
