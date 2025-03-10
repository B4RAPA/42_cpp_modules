/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:54:33 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/10 12:58:10 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nb_fractbits = 8;

Fixed::Fixed() : _fp_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &other)//selbstzuweisung aussschließen
		_fp_value = other.getRawBits();
	return (*this) ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBites member function called" << std::endl;
	return (this->_fp_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBites member function called" << std::endl;
	this->_fp_value = raw;
}


float Fixed::toFloat( void ) const
{
	return ((float)this->_fp_value / (float)(1 << this->_nb_fractbits));
}

int Fixed::toInt( void ) const
{
	return(this->_fp_value >> this->_nb_fractbits);
}
Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_value = (input << _nb_fractbits);
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fp_value = roundf(input *(1 << _nb_fractbits));
}


std::ostream& operator<<(std::ostream& os , const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}