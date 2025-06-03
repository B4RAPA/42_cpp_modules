/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:08:09 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 14:49:12 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits>

#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::lowest()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE std::numeric_limits<double>::lowest()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::lowest()

enum type {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	SPECIAL = 4,
	INVALID = 5
};

class ScalarConverter 
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
	

public:
	static void convert(const std::string& s);
};

type  find_type (const std::string& s);
void convert_int(const std::string& str);
void convert_char(const std::string& str);
void convert_float(const std::string& str);
void	convert_double(const std::string& str);
void convert_special(const std::string& str);
