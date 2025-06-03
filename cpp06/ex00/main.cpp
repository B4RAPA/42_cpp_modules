/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:29:55 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 14:52:58 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	std::cout << argv[1] << std::endl;
	ScalarConverter::convert(argv[1]);
	return (0);
}