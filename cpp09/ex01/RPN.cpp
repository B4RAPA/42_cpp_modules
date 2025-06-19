/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:20 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/04 12:42:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _mystack()
{

}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
	{
		this->_mystack = other._mystack;
	}
	return (*this);
}

RPN::~RPN()
{
	
}

void RPN::calc(char **argv)
{
	for (int i = 0; argv[1][i]; i++)
	{		
		if (isdigit(argv[1][i]))
		{
			this->_mystack.push(argv[1][i] - 48);
			continue;
		}
		if (argv[1][i] == 43 || argv[1][i] == 42 || argv[1][i] == 45 || argv[1][i] == 47)
		{
			if (_mystack.size() != 2)
				throw std::runtime_error("Error");
			int b = this->_mystack.top();
			this->_mystack.pop();
			int a = this->_mystack.top();
			this->_mystack.pop();
			if (argv[1][i] == 47 && (a == 0 || b == 0))
			{
				_mystack.push(0);
				continue;
			}
			if (argv[1][i] == 43)
				this->_mystack.push(a + b);
			else if (argv[1][i] == 42)
				_mystack.push(a * b);
			else if (argv[1][i] == 45)
				this->_mystack.push(a - b);
			else if (argv[1][i] == 47)
				_mystack.push(a / b);
			continue;
		}
		if (argv[1][i] != ' ')
			throw std::runtime_error("error");
	}
}

int RPN::getTop() const 
{
	if (_mystack.empty())
		throw std::runtime_error("stack empty");
	return _mystack.top();
}