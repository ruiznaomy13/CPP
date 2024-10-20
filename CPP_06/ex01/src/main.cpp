/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:30 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 22:05:41 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	// Crear una instancia de Data
	Data data1;
	data1.data = "Hello, World!";
	data1.num = 42;

	std::cout << GREEN"\n\t\t T E S T   # 1" << std::endl;
	std::cout << NC"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	// Serializar el puntero a Data
	unsigned long serializedData = Serializer::serialize(&data1);
	std::cout << "Serialized Data Pointer: " << serializedData << std::endl;

	// Deserializar el puntero
	Data* deserializedData = Serializer::deserialize(serializedData);
	
	// Verificar que el valor se mantiene
	std::cout << "Deserialized Data Value: " << deserializedData->data << " -->> " << deserializedData->num << std::endl;

	// Crear otra instancia de Data
	Data data2;
	data2.data = "Goodbye, World!";
	data2.num = 100;

	std::cout << GREEN"\n\t\t T E S T   # 2" << NC"" << std::endl;
	std::cout << NC"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	// Serializar el segundo puntero a Data
	unsigned long serializedData2 = Serializer::serialize(&data2);
	std::cout << "Serialized Data Pointer 2: " << serializedData2 << std::endl;

	// Deserializar el segundo puntero
	Data* deserializedData2 = Serializer::deserialize(serializedData2);
	
	// Verificar que el valor se mantiene
	std::cout << "Deserialized Data Value 2: " << deserializedData2->data << "--> " << deserializedData2->num << std::endl;

	return 0;
}