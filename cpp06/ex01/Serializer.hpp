/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:47:47 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 15:04:13 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include "data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=( const Serializer& other);
	~Serializer();
	
public:
	static uintptr_t serialize(Data* ptr);	
	static Data* deserialize(uintptr_t raw);
};