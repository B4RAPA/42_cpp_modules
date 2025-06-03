/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:36:38 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:17:25 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <iostream>

Span::Span(unsigned int N) : _maxsize(N)
{
	_span.reserve(N); 
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxsize = other._maxsize;
		this->_span = other._span;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (this->_span.size() >= this->_span.capacity())
	{
		throw ContainerFull();
	}
	else
		this->_span.push_back(n);
}

int Span::shortestSpan() const
{
	try{
		if (this->_span.size() < 2)
			throw EmptyContainer();
	}catch (EmptyContainer& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
	std::vector<int> sort = _span;
	std::sort(sort.begin(), sort.end());
	
	int minSpan = std::numeric_limits<int>::max();
	for (long unsigned int i = 1; i < sort.size(); i++)
	{
		int j = sort[i] - sort[i - 1];
		if (j < minSpan)
			minSpan = j;
	}
	return(minSpan);
}

int Span::longestSpan() const
{
	try{
		if (this->_span.size() < 2)
			throw EmptyContainer();
	}catch (EmptyContainer& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
	int minVal = *std::min_element(this->_span.begin(), this->_span.end());
	int maxVal = *std::max_element(this->_span.begin(), this->_span.end());
	return (maxVal - minVal);
}

const char* Span::ContainerFull::what() const throw()
{
	return ("Container Full");
}

const char* Span::EmptyContainer::what() const throw()
{
	return ("Not enough numbers in this Container");
}