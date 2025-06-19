/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:27:48 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/19 13:17:38 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <iosfwd>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <map>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error could not open file" << std::endl;
		return (0);
	}
	std::fstream fin;
	fin.open(argv[1], std::ios::in);
	// std::map<std::string, float> row{argv, date};
	std::string line, word;
	bool	first_line = true;
	while (std::getline(fin, line))
	{
		if (first_line)
		{
			first_line = false;
			continue;
		}
		// row.clear();
		std::stringstream ss(line);
		while (std::getline(ss, word, ss.widen('\n')))
		{
			// row.push_back(word);
		}
		// if (!row.empty())
		{
			// for (int i = 0; i < static_cast<int>(row.size()); i++)
			{
				// validate(row[i]);
			}
		}
	}
}