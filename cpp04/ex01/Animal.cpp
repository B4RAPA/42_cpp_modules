/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:39:51 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 13:28:55 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unidentified")
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal  Copy Constructor called" << std::endl;
	*this = copy;
	return;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
	return ;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}

void Animal::makeSound( void ) const
{
	std::cout << "Some weird Animal Sounds" << std::endl;
	return ;
}