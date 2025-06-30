/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:27:48 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/27 12:30:28 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <iosfwd>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <map>

int main(int argc, char** argv)
{
	BitcoinExchange exchange;
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::ifstream fin(argv[1]);
	if (!fin)
	{
		std::cerr << "Error: failed to open file " << argv[1] << std::endl;
		return 1;
	}

	std::string line;
	bool first_line = true;

	while (std::getline(fin, line))
	{
		if (first_line)
		{
			first_line = false;
			continue;
		}

		if (!line.empty())
		{
			exchange.validate(line);
		}
	}

	return 0;
}
