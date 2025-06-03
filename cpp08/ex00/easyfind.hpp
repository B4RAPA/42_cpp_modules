/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:21:09 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/02 11:00:14 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

class ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return("Value not found");
		}
};

template <typename T>
typename T::iterator easyfind(T& c, int i)
{
	typename T::iterator ret;
	ret = std::find(c.begin(), c.end(), i);
	if (ret == c.end())
	{
		throw ValueNotFound();
		return (ret);
	}
	std::cout << i << " Is part of the vector " << std::endl;
	return (ret);
}

template <typename T>
typename T::const_iterator easyfind(const T& c, int i)
{
	typename T::const_iterator ret;
	ret = std::find(c.begin(), c.end(), i);
	if (ret == c.end())
	{
		throw ValueNotFound();
		return (ret);
	}
	std::cout << i << " Is part of the vector " << std::endl;
	return (ret);
}
