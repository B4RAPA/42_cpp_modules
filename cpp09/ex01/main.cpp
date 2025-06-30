/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:18 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/27 12:10:49 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	RPN mystack;
	try{
		mystack.calc(argv);
		std::cout << mystack.getTop() << std::endl;
	} catch (const std::runtime_error& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
