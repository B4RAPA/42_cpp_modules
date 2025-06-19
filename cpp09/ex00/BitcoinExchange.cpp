/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:58:13 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 13:50:37 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <map>
#include <cstdlib>
#include <algorithm>

void	validate_date(std::string row)
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
			}
			else if(!std::isdigit(static_cast<unsigned char>(row[i])))
			{
				throw DateNotValidException();
				return;
			}
		}
	}
}

bool	validate_value(std::string row)
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

const char* DateNotValidException::what() const throw()
{
	return ("Date is not valid. Has to be in format: YYYY-MM-DD.");
}

const char* NotAPositiveNumberException::what() const throw()
{
	return ("number is not positive");
}

const char* NumberTooHighException::what() const throw()
{
	return ("number to large");
}


void validate(std::string row)
{
	if(!row.empty())
	{	
		try{
			validate_date(row);
			validate_value(row);
			std::string date = row.substr(0, 10);
			std::string amount = row.substr(13);
			std::cout << date << " => ";  // nur wenn wirklich Daten vorhanden sind
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

float	get_exchange_rate(std::string date)
{
	std::fstream fin;
	float f_upper;
	float f_lower;
	float rate;
	float f_min;
	fin.open("data.csv", std::ios::in);
	if (!fin)
		return (0.0f);
	std::vector<std::string> row;
	std::string line, csv_date, csv_rate;
	std::map<std::string, float> date_to_rate;
	while (std::getline(fin, line))
	{
		std::stringstream ss(line);
	
		if (!std::getline(ss, csv_date, ','))
			continue;
		if (!std::getline(ss , csv_rate))
			continue;
		char *end;
		rate = static_cast<float>(std::strtod(csv_rate.c_str(), &end));
		date_to_rate[csv_date] = rate;
	}
	std::map<std::string, float>::iterator it = date_to_rate.find(date);
	if (it != date_to_rate.end())
		return (it->second);
	
	std::map<std::string, float>::iterator lower = date_to_rate.lower_bound(date);
	if (lower != date_to_rate.end())
	{
		f_lower = lower->second;
	}
	std::map<std::string, float>::iterator upper = date_to_rate.upper_bound(date);
	if (upper != date_to_rate.end())
		f_upper = upper->second;
	if (f_upper - rate < rate - f_lower)
		f_min = f_upper;
	else
		f_min = f_lower;
	return (f_min);
}
