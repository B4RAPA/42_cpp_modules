/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:28:05 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/27 12:36:37 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <ctime>




class BitcoinExchange
{
private:

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	void	validate_date(std::string row);
	bool	validate_value(std::string row);
	void	validate(std::string row);
	float	get_exchange_rate(std::string date);
	class DateNotValidException : public std::exception
	{
		public:	
			virtual const char* what() const throw();
	};
	
	class NotAPositiveNumberException : public std::exception
	{
		public:	
			virtual const char* what() const throw();
	};
	class NumberTooHighException : public std::exception
	{
		public:	
			virtual const char* what() const throw();
	};
	
};