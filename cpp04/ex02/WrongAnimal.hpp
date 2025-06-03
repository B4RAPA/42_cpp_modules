/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:41:28 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 13:28:19 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
	
public:
	WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& other);
	WrongAnimal(const WrongAnimal& copy);
	virtual ~WrongAnimal();

	std::string getType( void ) const;
	virtual void makeSound( void ) const;
	
};