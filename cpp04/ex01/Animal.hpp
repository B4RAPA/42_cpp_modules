/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:31:50 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 13:17:26 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	std::string _type;
	
public:
	Animal();
	Animal& operator=(const Animal& other);
	Animal(const Animal& copy);
	virtual ~Animal();

	std::string getType( void ) const;
	virtual void makeSound( void ) const;
	
};