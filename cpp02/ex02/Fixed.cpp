/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:54:33 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/10 14:33:54 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nb_fractbits = 8;

Fixed::Fixed() : _fp_value(0)
{
	// std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignation operator called" << std::endl;
	if (this != &other)//selbstzuweisung aussschließen
		_fp_value = other.getRawBits();
	return (*this) ;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBites member function called" << std::endl;
	return (this->_fp_value);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBites member function called" << std::endl;
	this->_fp_value = raw;
}


float Fixed::toFloat( void ) const
{
	return ((float)this->_fp_value / (1 << this->_nb_fractbits));
}

int Fixed::toInt( void ) const
{
	return(this->_fp_value >> this->_nb_fractbits);
}
Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fp_value = (input << _nb_fractbits);
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fp_value = roundf(input *(1 << _nb_fractbits));
}


std::ostream& operator<<(std::ostream& os , const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed res;
	res._fp_value = _fp_value + fixed._fp_value;
	return (res);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed res;
	res._fp_value = _fp_value - fixed._fp_value;
	return (res);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed res;
	res._fp_value = (_fp_value * fixed._fp_value) >> _nb_fractbits;
	return (res);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed res;
	res._fp_value = (_fp_value / fixed._fp_value);
	return (res);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (_fp_value < fixed._fp_value);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (_fp_value > fixed._fp_value);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	if (_fp_value <= fixed._fp_value)
		return (true);
	return (false);	
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	if (_fp_value >= fixed._fp_value)
		return (true);
	return (false);	
}


bool Fixed::operator==(const Fixed& fixed) const
{
	if (_fp_value == fixed._fp_value)
		return (true);
	return (false);	
}


bool Fixed::operator!=(const Fixed& fixed) const
{
	if (_fp_value != fixed._fp_value)
		return (true);
	return (false);	
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fp_value ++;
	return (temp);
}

Fixed& Fixed::operator++()
{
	this-_fp_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fp_value--;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed& Fixed::max( Fixed& fixed, Fixed& fixed2)
{
	if (fixed._fp_value > fixed2._fp_value)
		return (fixed);
	return (fixed2);
}

const Fixed& Fixed::max( const Fixed& fixed, const Fixed& fixed2)
{
	if (fixed._fp_value > fixed2._fp_value)
		return (fixed);
	return (fixed2);
}

Fixed& Fixed::min( Fixed& fixed, Fixed& fixed2)
{
	if (fixed._fp_value < fixed2._fp_value)
		return (fixed);
	return (fixed2);
}

const Fixed& Fixed::min( const Fixed& fixed, const Fixed& fixed2)
{
	if (fixed._fp_value < fixed2._fp_value)
		return (fixed);
	return (fixed2);
}