/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:31:19 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/02 12:16:04 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
private:
	std::vector<int> _span;
	int				 _maxsize;
public:
	Span(const unsigned int N);
	Span& operator=(const Span& other);
	Span(const Span& copy);
	void addNumber(int n);
	template<typename Iterator>
	void addNumber (Iterator begin, Iterator end)
	{
		if (_span.size() + std::distance(begin, end) > this->_span.capacity())
		{
			throw ContainerFull();
		}
		_span.insert(_span.end(), begin, end);
	}
	int shortestSpan() const;
	int longestSpan() const;
	
	class EmptyContainer : public std::exception
	{
		public:
			const char *what() const throw();	
	};
	class ContainerFull : public std::exception
	{
		public:
			const char *what() const throw();	
	};
	~Span();
};