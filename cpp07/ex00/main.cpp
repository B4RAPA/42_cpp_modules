/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:42:28 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/27 16:06:05 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// int main()
// {
// 	char i = 'a';
// 	char j = 'b';
// 	std::cout << "i: " << i << " j: " << j << std::endl;
// 	swap(i, j);
// 	std::cout << "min: " << min(i, j) << std::endl;
// 	std::cout << "max: " <<  max(i, j) << std::endl;
// 	std::cout << "i: " << i << " j: " << j << std::endl;

// 	std::cout << std::endl;
// 	int a = 4;
// 	int b = 5;
// 	std::cout << "a: " << a << " b: " << b << std::endl;
// 	swap(a, b);
// 	std::cout << "min: " << min(a, b) << std::endl;
// 	std::cout << "max: " <<  max(a, b) << std::endl;
// 	std::cout << "a: " << a << " b: " << b << std::endl;

// 	std::cout << std::endl;
// 	std::string c = "hallo";
// 	std::string d = "Moin";
// 	std::cout << "c: " << c << " d: " << d << std::endl;
// 	swap(c, d);
// 	std::cout << "min: " << min(c, d) << std::endl;
// 	std::cout << "max: " <<  max(c, d) << std::endl;
// 	std::cout << "c: " << c << " d: " << d << std::endl;

// 	float f = 4.2f;
// 	float e = 5.1f;
// 	std::cout << std::endl;
// 	std::cout << "e: " << e << " f: " << f << std::endl;
// 	swap(e, f);
// 	std::cout << "min: " << min(e, f) << std::endl;
// 	std::cout << "max: " <<  max(e, f) << std::endl;
// 	std::cout << "e: " << e << " f: " << f <<  std::endl;
	
// }

int main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}