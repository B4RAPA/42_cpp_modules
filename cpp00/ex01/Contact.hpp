/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:52:48 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/06 13:05:34 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cctype>
# include <iostream>
# include <cstring>
#include <iomanip> 

class Contact
{
private:
	
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	phone_number;
	
public:

	Contact();
	bool add_contact();
	std::string get_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_darkest_secret() const;
	std::string get_phone_number() const;
	void print_contacts(int index) const;
	void print_contact(int index) const;
};


#endif