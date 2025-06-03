/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:43:26 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/20 13:43:27 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( const WrongCat& copy): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound() const 
{
	std::cout << "Buuh" << std::endl;
	return ;
}