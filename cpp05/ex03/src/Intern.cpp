/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:49:14 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/27 10:05:14 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor for Intern called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Copy constructor for Intern called" << std::endl;
	(void)copy;
}

Intern & Intern::operator=(const Intern& other)
{
	std::cout << "Assignation operator for Intern called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor for Intern called" << std::endl;
}

AForm *Intern::makeForm(const std::string form_name, const std::string target)
{
	int		nb;

	nb = (form_name == "RobotomyRequestForm" ?  0 : //in einen enum packen
			(form_name == "ShrubberyCreationForm" ? 1 :
			(form_name == "PresidentialPardonForm" ? 2 : 
				3)));
	switch (nb)
	{
	case 0:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new RobotomyRequestForm(target));
	case 1:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new ShrubberyCreationForm(target));
	case 2:
		std::cout << "Intern creates " << form_name << std::endl;
		return (new PresidentialPardonForm (target));
	default:
		std::cout << "Form is not existing" << std::endl;
		return 0;
	}	
}
