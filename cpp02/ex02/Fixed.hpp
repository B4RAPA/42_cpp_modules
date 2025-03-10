/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:54:30 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/10 14:15:14 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fp_value;
	static const int _nb_fractbits;

public:
	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed& copy);
	
	~Fixed();
	
	Fixed& operator=(const Fixed& other);
	
	float toFloat( void ) const;
	int toInt( void ) const;
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	bool operator<(const Fixed& fixed) const;
	bool operator>(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;
	
	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;
	
	Fixed operator++(int);
	Fixed& operator++();
	Fixed operator--(int);
	Fixed& operator--();

	static Fixed &max( Fixed& fixed, Fixed& fixed2);
	static const Fixed &max( const Fixed& fixed, const Fixed& fixed2);
	
	static Fixed &min( Fixed& fixed, Fixed& fixed2);
	static const Fixed &min( const Fixed& fixed, const Fixed& fixed2);

};

std::ostream& operator<<(std::ostream& os , const Fixed& fixed);
