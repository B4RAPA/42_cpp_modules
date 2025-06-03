/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:41:18 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/20 13:42:19 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unidentified")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Assignation Operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
	return;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal flew away" << std::endl;
	return ;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Some weird WrongAnimal Sounds" << std::endl;
	return ;
}