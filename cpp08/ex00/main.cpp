/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:06:41 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:14:25 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 2};
    std::vector<int> vec(arr, arr + 6);
	int i = 6;
	try{
		easyfind(vec, i);
	}
	catch (const ValueNotFound& e)
	{
		std::cout << "Exception caught: " << e.what() << " " << i << std::endl;
	}
	try{
		easyfind(vec, 2);
	}
	catch (const ValueNotFound& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try {
		easyfind(vec, 3);
	}	catch (const ValueNotFound& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}