/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:58:13 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/27 12:35:43 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <map>
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other; 
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::validate_date(std::string row)
{
	if(!row.empty())
	{
		for(int i = 0; i < 10; i++)
		{
			if(i == 4 || i == 7)
			{
				if(row[i] != '-')
				{
					throw DateNotValidException();
					return;
				}
				if (i == 4 && row[5] == '1' && row[6] > '2')
				{
					throw DateNotValidException();
					return;
				}
				else if ((i == 7 && row[8] > '3') || (i == 7 && row[8] >= '3' && row[9] > '0'))
				{
					throw DateNotValidException();
					return;
				}
			}
			else if(!std::isdigit(static_cast<unsigned char>(row[i])))
			{
				throw DateNotValidException();
				return;
			}
		}
	}
}

bool	BitcoinExchange::validate_value(std::string row)
{
	std::string numStr = row.substr(12);
	try	{
		char *end;
		float number = static_cast<float>(std::strtod(numStr.c_str(), &end));
		if (number >= 0.0 && number <= 1000.0)
			return (true);
		else if (number <= 0)
			throw NotAPositiveNumberException();
		else if (number > 1000.0)
			throw NumberTooHighException();
	}
	catch (const std::invalid_argument& e)
	{
		return (false);
	} catch (const std::out_of_range& e)
	{
		return (false);
	}
	return (false);
}

const char* BitcoinExchange::DateNotValidException::what() const throw()
{
	return ("Date is not valid. Has to be in format: YYYY-MM-DD.");
}

const char* BitcoinExchange::NotAPositiveNumberException::what() const throw()
{
	return ("number is not positive");
}

const char* BitcoinExchange::NumberTooHighException::what() const throw()
{
	return ("number to large");
}


void BitcoinExchange::validate(std::string row)
{
	if(!row.empty())
	{	
		try{
			validate_date(row);
			validate_value(row);
			std::string date = row.substr(0, 10);
			std::string amount = row.substr(13);
			std::cout << date << " => ";
			std::cout << amount << " = ";
			float f_amount = static_cast<float>(std::strtod(amount.c_str(), NULL));
			float sell = f_amount * get_exchange_rate(date);
			std::cout << sell << std::endl;
		} catch(const DateNotValidException& e) {
			std::cout << "Error: " << e.what() << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "Error:  " << "bad input => " << row << std::endl;
		} catch (const NumberTooHighException& e) {
			std::cout << "Error:  " << e.what() << std::endl;
		} catch (const NotAPositiveNumberException& e) {
			std::cout << "Error:  " << e.what() << std::endl;
		}
	}
}

float	BitcoinExchange::get_exchange_rate(const std::string date)
{
	std::fstream fin;
	float rate;
	fin.open("data.csv", std::ios::in);
	if (!fin)
		return (0.0f);
	std::map<std::string, float> row;
	std::string line, csv_date, csv_rate;
	while (std::getline(fin, line))
	{
		std::stringstream ss(line);
	
		if (!std::getline(ss, csv_date, ','))
			continue;
		if (!std::getline(ss , csv_rate))
			continue;
		char *end;
		rate = static_cast<float>(std::strtod(csv_rate.c_str(), &end));
		row[csv_date] = rate;
	}
	std::map<std::string, float>::iterator it = row.find(date);
	if (it != row.end())
		return (it->second);
	std::map<std::string, float>::iterator upper = row.upper_bound(date);
	if (upper == row.end())
	{
		upper = row.end()--;
		return (upper->second);
	}
	std::map<std::string, float>::iterator lower;
	lower = upper;
	if (lower != row.begin())
		--lower;
	return (lower->second);
}
