/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:45:04 by ncastell          #+#    #+#             */
/*   Updated: 2024/10/20 21:59:42 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "[SERIALIZER] Constructor Called" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "[SERIALIZER] Destructor Called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    *this = other;
	std::cout << "[SERRIALIZER] Copy Constructor Called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
	std::cout << "[SERIALIZER] Copy Assignment Operator Called" << std::endl;
    (void)other;
    return (*this);
}

unsigned long Serializer::serialize(Data* ptr)
{
    std::cout << "[SERIALIZER] Serializer" << std::endl;
    unsigned long ret_ptr = reinterpret_cast<unsigned long>(ptr);
    return (ret_ptr);
}

Data* Serializer::deserialize(unsigned long raw)
{
    std::cout << "[SERIALIZER] Deserializer" << std::endl;
    Data* ret_data = reinterpret_cast<Data*>(raw);
    return (ret_data);
}