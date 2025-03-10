/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:24:47 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/05 09:45:43 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

int main()
{
    PhoneBook phonebook;
	std::string input;
	int			index;
	int			i;

	while (input != "EXIT")
	{
		std::cout << "Enter ADD, SEARCH or EXIT " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting Phonebook" << std::endl;
			break ;
		}
		if (input == "ADD")
    		phonebook.add_contact();
		else if (input == "SEARCH")
		{
			phonebook.print_contacts();
			std::cout << "Enter Number " << std::endl;
			std::getline(std::cin, input);
			index = std::atoi(input.c_str());
			if (index > 7 || !isNumber(input))
				std::cout << "Please pick a valid Contact" << std::endl;
			else if (index >= phonebook.get_nb_contacts())
				std::cout << "Contact does not exit" << std::endl;
			else
				phonebook.print_contact(index);
		}
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting Phonebook" << std::endl;
			break ;
		}
	}
	
    return (0);
}