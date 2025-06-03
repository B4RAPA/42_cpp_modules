/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:14:11 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:05:05 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t raw;
	Data *test;
	data.Day = 27;
	data.Month = 05;
	data.Year = 2025;
	std::cout << data.Day << "  " <<  data.Month << "  " << data.Year << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << &raw << std::endl;
	test = Serializer::deserialize(raw);
	std::cout << test->Day << "  " <<  test->Month << "  " << test->Year << std::endl;
}