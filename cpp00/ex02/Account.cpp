/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:10:17 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/04 10:36:17 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);	
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout <<
	"accounts:" << getNbAccounts() << ";" <<
	"total:" << getTotalAmount() << ";" <<
	"deposits:" << getNbDeposits() << ";" <<
	"withdrawls:" << getNbWithdrawals() <<
	std::endl;
}

Account::Account( int initial_deposit )
{
	// Init all the start-values of each account
	// and keep track of the number of accounts as well as the total ammount of money
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts ++;

	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";" << 
	"created" << 
	std::endl;
 	// Printing note of the creation of the Account with its starting values and the state created
}

Account::~Account( void )
{
	// destructor that prints all the ending values as well as the state closed
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";" << 
	"closed" << 
	std::endl;

}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << 
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->_amount << ";" ;
	
	this->_amount += deposit;
	this->_nbDeposits ++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << 
	"deposit:" << deposit << ";" <<
	"amount:" << this->_amount << ";" <<
	"nb_deposits:" << this->_nbDeposits << 
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << 
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->_amount << ";" ;
	if (this->checkAmount() > withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals ++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount = Account::_totalAmount - withdrawal;
		std::cout << 
		"withdrawal:" << withdrawal << ";" <<
		"amount:" << this->_amount << ";" <<
		"nb_withdrawals:" << this->_nbWithdrawals << 
		std::endl;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;	
		return (false);	
	}
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";" <<
	"deposits:" << this->_nbDeposits << ";" <<
	"withdrawls:" << this->_nbWithdrawals <<
	std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t current_time = std::time(0);
	std::tm* localTime = std::localtime(&current_time);
	
	std::cout <<
	"[" <<
	(localTime->tm_year + 1900) <<
	"0" << (localTime->tm_mon + 1) << 
	"0" << localTime->tm_mday <<
	"_" <<
	localTime->tm_hour <<
	localTime->tm_min <<
	localTime->tm_sec << 
	"]" ;
}
