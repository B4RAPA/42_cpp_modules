/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:33:25 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/30 10:52:09 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	std::vector<int> test_data;
	std::deque<int> test_data2;
	for (int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		test_data.push_back(num);
		test_data2.push_back(num);
	}
	std::cout << "before: ";
	for (int k = 0; k < argc - 1&& k < 10; k++)
	{
		std::cout << test_data[k] << " ";
	}
	std::cout << "[...]" << std::endl;
	PmergeMe sorter;
	std::clock_t start = std::clock();
	sorter.sort(test_data);
	std::clock_t end = std::clock();
	double elapsed_ms_vector = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	start = std::clock();
	sorter.sort(test_data2);
	end = std::clock();
	double elapsed_ms_deque = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "after: ";
	for (int k = 0; k < argc -1 && k < 10; k++)
	{
		std::cout << test_data[k] << " ";
	}
	std::cout << "[...]" << std::endl;
	std::cout << "Time to proccess a range of " << argc - 1 << " elements with type std::vector" << " : " << elapsed_ms_vector << std::endl; 
	std::cout << "Time to proccess a range of " << argc - 1 << " elements with type std::deque " << " : " << elapsed_ms_deque << std::endl;
	return 0;
}