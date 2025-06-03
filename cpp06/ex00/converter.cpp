/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:51:51 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 14:59:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convert_float(const std::string& str)
{
	char *end;
	double d = std::strtod(str.c_str(), &end);

	float f = static_cast<float>(d);
	int zahl = static_cast<int>(d);
	char c = static_cast<char>(zahl);
	if (zahl <= 32 || zahl > 127)
		std::cout << "char is non printable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << zahl << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void convert_int(const std::string& str)
{
	long i = std::atol(str.c_str());
	if (i >= 32 && i <= 127)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char is non printable" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convert_char(const std::string& str)
{
	const char *c = str.c_str();
	
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(*c) << std::endl;
	std::cout << "float: " << static_cast<float>(*c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(*c) << ".0" << std::endl;
}

void convert_double(const std::string& str)
{
	char *end;
	double d = std::strtod(str.c_str(), &end);

	float f = static_cast<float>(d);
	int zahl = static_cast<int>(d);
	char c = static_cast<char>(zahl);
	if (zahl <= 32 || zahl > 127)
		std::cout << "char is non printable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << zahl << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

type  find_type (const std::string& s)
{
	std::cout << s << std::endl;
	size_t p = s.find('.');
	size_t f = s.find('f');
	size_t len = s.length();
	std::cout << len << std::endl;
	if (p == std::string::npos)
	{
		if (s == "nanf" || s == "nan" || s == "-inff" || s == "+inff" || s == "-inf" || s == "inf")
			return (SPECIAL);
		if (s[0] <= '9' && s[0] >= '0')
			return(INT);
		else
			return (CHAR);
	}
	else if (len == 4 && p != std::string::npos && f == std::string::npos)
		return (DOUBLE);
	else if (len == 5 && f != std::string::npos && p != std::string::npos)
		return (FLOAT);
	return (INVALID);
}

void convert_special(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "Char: impossible" << "\n"
		<< "Int: impossible" << "\n" 
		<< "Float: nanf" << "\n"
		<< "Double: nan" << std::endl;	
	}
	if (str == "inff" || str == "inf")
	{
		std::cout << "Char: impossible" << "\n"
		<< "Int: impossible" << "\n" 
		<< "Float: inff" << "\n"
		<< "Double: inf" << std::endl;	
	}
	if (str == "-inff" || str == "-inf")
	{
		std::cout << "Char: impossible" << "\n"
		<< "Int: impossible" << "\n" 
		<< "Float: -inff" << "\n"
		<< "Double: -inf" << std::endl;	
	}
}