/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:51:15 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/06 12:56:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <cctype>
# include <iostream>
# include <cstring>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact				contact;
	static const int	CAPACITY = 8;
	Contact 			*contacts[CAPACITY];
	int					nb_contacts;

public:
	PhoneBook();
	PhoneBook(const Contact &contact);
	bool add_contact();
	void print_contact(int index);
	void print_contacts();
	int get_nb_contacts() const ;
	void get_amount();
	~PhoneBook();

};

#endif