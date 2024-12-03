/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:45:04 by ncastell          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:43 by ncastell         ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << "[SERIALIZER] Serializer" << std::endl;
    uintptr_t ret_ptr = reinterpret_cast<uintptr_t>(ptr);
    return (ret_ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << "[SERIALIZER] Deserializer" << std::endl;
    Data* ret_data = reinterpret_cast<Data*>(raw);
    return (ret_data);
}