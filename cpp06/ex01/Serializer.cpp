/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:07:15 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:04:26 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) {(void)copy;}

Serializer& Serializer::operator=( const Serializer& other)
{
	if (this != &other) {}
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
