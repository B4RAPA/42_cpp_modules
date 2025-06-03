/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:07:10 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:11:33 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstdlib>
\
int main(void)
{
	const size_t len = 5;
	const int array[len] = {1, 2, 3, 4, 5};
	iter(array, len, ft_out);

	std::cout << "\n" << std::endl;
	size_t len_arr = 9;
	int arr[len_arr];
	for (size_t i = 0; i < len_arr; i++)
	{
		arr[i] = 0 + rand() % (100 - 0 + 1); 
	}
	iter(arr, len_arr, ft_out);
	std::cout << "\n" << std::endl;
	for (size_t i = 0; i < len_arr; i++)
	{
		std::cout << "Array for comparison: " << arr[i] << std::endl;
	}
	ft_out(arr[0]);
	std::cout << "\n" << std::endl;
	char c_arr[4] = {'a', 'b', 'c', 'd'};
	iter (c_arr, 4, ft_out);
	std::cout << "\n" << std::endl;
	float f_arr[4] = {1.0f, 2.0f, 3.1f, 42.42f};
	iter (f_arr, 4, ft_out);
	for ( int i = 0; i < 4; i++)
	{
		std::cout << "Array for comparison: " << f_arr[i] << std::endl;
	}
}