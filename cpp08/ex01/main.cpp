/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:25:31 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:16:57 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>

int main(void)
{
	srand(time(0));
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << '\n' <<  "test with empty span" <<'\n';
	Span test_sp = Span(2);
	try{
		std::cout << test_sp.longestSpan() << std::endl;
	} catch(Span::EmptyContainer& e){} 
	catch(Span::ContainerFull& e) {}
	
	std::cout << '\n' <<  "test with all in one add_number function" <<'\n';
	Span test2_sp = Span(20);
	int arr[] = {12, 12, 4214 , 123, 1, 2, 1};
	std::vector<int> v(arr, arr + 7);
	test2_sp.addNumber(v.begin(), v.end());
	std::cout << test2_sp.shortestSpan() << std::endl;
	std::cout << test2_sp.longestSpan() << std::endl;
	
	std::cout << '\n' << "test 50k numbers" <<'\n';
	Span test50k = Span(50000);
	std::vector<int> big;
	big.reserve(40000);
	for (int i = 0; i < 40000; i++)
	{
		big.push_back(rand());
	}
	test50k.addNumber(big.begin(), big.end());
	std::cout << test50k.shortestSpan() << std::endl;
	std::cout << test50k.longestSpan() << std::endl;
	Span test_4 = Span(4);
	try{
		test_4.addNumber(v.begin(), v.end());
	} catch( const Span::ContainerFull& e)
	{
		std::cout << "Exception caught: "<< e.what() << std::endl;
	}
}