/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:14:36 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/06 14:22:55 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : name(""), last_name(""), nickname(""), darkest_secret(""), phone_number("") {}

// Contact::Contact(const std::string &name, const std::string &last_name, const std::string &nickname,
// 	const std::string &darkest_secret, const std::string &phone_number)
// : name(name), last_name(last_name), nickname(nickname),
//   darkest_secret(darkest_secret), phone_number(phone_number) {}
	  
bool Contact::add_contact()
{
	const std::string prompts[] = 
	{
		"Please input Name",
		"Please input Last Name",
		"Please input Nickname",
		"Please input theire Darkest Secret",
		"Please input theire Phone Number"
	};

	std::string* fields[] = {&name, &last_name, &nickname, &darkest_secret, &phone_number};
	
	std::string input;
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << prompts[i] << std::endl;
		if( !std::getline(std::cin, input))
		{
			std::cerr << "An error occured" << std::endl;
			return (false);
		}
		while (input.empty())
		{
			// std::getline(std::cin, input);
			if( !std::getline(std::cin, input))
			{
				std::cerr << "An error occured" << std::endl;
				return (false);
			}

		}
		*fields[i] = input;
		
	}
	return (true);
}

std::string formatString(const std::string& str)
{
	std::string result = str;
	if (str.length() > 10)
	{
		result = str.substr(0, 9) + '.'; 
		return (result);
	}
	return (str);
}

void Contact::print_contact(int index) const
{
	std::stringstream ss;
	ss << index;
	std::string str = ss.str();

	const char *cstr = str.c_str();
	std::cout << std::right
			  << "Number: " <<  cstr << '\n'
			  << "Name: " << name << '\n'
			  << "Last Name: " << last_name << '\n'
			  << "Nickname: " << nickname << '\n'
			  << "Darkes Secret: " << darkest_secret
			  << std::endl;
}

void Contact::print_contacts(int index) const
{
	std::stringstream ss;
	ss << index;
	std::string str = ss.str();

	const char *cstr = str.c_str();

	std::cout << std::right
			  << std::setw(10)  << formatString(cstr) << "|"
			  << std::setw(10) << formatString(name) << "|"
			  << std::setw(10) << formatString(last_name) << "|"
			  << std::setw(10) << formatString(nickname) << "|"
			  << std::endl;
}
std::string Contact::get_name() const
{ 
	return name;
}

std::string  Contact::get_last_name() const
{
	return last_name;
}

std::string  Contact::get_nickname() const
{
	return nickname;
}

std::string  Contact::get_darkest_secret() const
{
	return darkest_secret;
}

std::string  Contact::get_phone_number() const
{
	return phone_number;
}