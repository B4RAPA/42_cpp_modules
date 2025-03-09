
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : fixed_value(0)
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
		fixed_value = other.getRawBits();
	return (*this) ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBites member function called" << std::endl;
	return (this->fixed_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBites member function called" << std::endl;
	this->fixed_value = raw;
}