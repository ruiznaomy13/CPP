/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:16:52 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/16 00:55:13 by ncastell         ###   ########.fr       */
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
    std::string s1 = argv[2];
    std::string s2 = argv[3];
	FileReplacer FileReplacer(filename);
	FileReplacer.readFromFile();
}

// int	main()
// {
// 	std::ifstream				inputFile("file.txt");
// 	std::string					line;
// 	std::vector<std::string>	names;

// 	if (!inputFile)
// 	{
// 		std::cout << "Error al abrir ejemplo.dat\n";
// 		exit(EXIT_FAILURE);
// 	}
	
// 	while (getline(inputFile, line))
// 		names.push_back(line);

//     for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it)
//         std::cout << *it << std::endl;

// 	return 0;
// }