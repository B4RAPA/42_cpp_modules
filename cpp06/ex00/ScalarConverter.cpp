/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:11:27 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:03:38 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& s)
{
	type 	i;
	i = find_type(s);
	switch(i)
	{
		case CHAR:
			convert_char(s);
			break;
		case INT:
			convert_int(s);
			break;
		case FLOAT:
			convert_float(s);
			break;
		case DOUBLE:
			convert_double(s);
			break;
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			break;
		case SPECIAL:
			convert_special(s);
			break;
	}
}
