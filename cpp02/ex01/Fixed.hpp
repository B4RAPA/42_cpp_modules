#pragma once

#include <iostream>

class Fixed
{
private:
	int fixed_value;
	static const int nb_fractbits;

public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	Fixed& operator=(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed(const int fuck_u);
	Fixed(const float and_u_two);
	float toFloat( void ) const;
	int toInt( void ) const;
	
};