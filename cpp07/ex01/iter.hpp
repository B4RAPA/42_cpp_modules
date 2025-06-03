/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:07:08 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/30 11:56:54 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*func)(T &))
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void iter(const T *array, size_t len, void (*func)(const T &))
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T>
void ft_out(T& arr)
{
	std::cout << arr << std::endl;	
}