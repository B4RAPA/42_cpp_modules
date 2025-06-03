/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:57:45 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 13:13:18 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog& copy): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=( const Dog& other)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
	return ;
}