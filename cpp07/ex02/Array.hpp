/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:24:07 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:12:58 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>

template<class T>
class Array
{
private:
	T* 	_array;
	unsigned int _n;
public:

	Array() : _n(0)
	{
		_array = new T[_n];
	}
	
	Array(const unsigned int n) : _n(n)
	{
		_array = new T[_n];
	}
	
	Array(const Array& copy)
	{
		_n = copy._n;
		_array = new T[_n]; 
		for(unsigned int i = 0; i < _n; i++)
		{
			_array[i] = copy._array[i];
		}
		
	}
	
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _array;
			_n = other._n;
			_array = new T[_n];
			for (int i = 0; i < _n; i++)
			{
				_array[i] = other._array[i];
			} 
		}
		return (*this);
	}

	T& operator[](int index)
	{
		if (index < 0)
			throw Array<T>::IndexTooLow();
		if (static_cast<unsigned int>(index) >= _n)
			throw Array<T>::IndexTooHigh();
		return (this->_array[index]);
	}

	T operator [](int index) const {
		if (index < 0)
			throw Array<T>::IndexTooLow();
		if (static_cast<unsigned int>(index) >= _n)
			throw Array<T>::IndexTooHigh();
        return (this->_array[index]);
    }
	
	unsigned int size() const
	{
		return (this->_n);
	}
	
	class IndexTooHigh : public std::exception
	{
		public:
			IndexTooHigh(){};
			virtual const char* what() const throw();
	};
	class IndexTooLow : public std::exception
	{
		public:
			IndexTooLow(){};
			virtual const char* what() const throw();
	};

	~Array()
	{
		if (_array != NULL)
			delete[] _array;
	}
};

template <typename T>
const char* Array<T>::IndexTooLow::what() const throw(){
	return ("Index to Low");
}

template <typename T>
const char* Array<T>::IndexTooHigh::what() const throw(){
	return ("Index to High");
}