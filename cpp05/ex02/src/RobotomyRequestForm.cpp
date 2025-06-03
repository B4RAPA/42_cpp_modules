/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:14:20 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:23:07 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "Default constructor for RobotomyRequestForm has been called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parametrized constructor for RobotomyRequestForm has been called" << std::endl;


}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	std::cout << "Copy Constructor for RobotomyRequestForm has been called" << std::endl;	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Assignation operator for RobotomyRequestForm has been called" << std::endl;	
	if (this != &other)
		*this = other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor for RobotomyRequestForm has been called" << std::endl;
}

void RobotomyRequestForm::performAction() const
{
	std::cout << "*drilling noise*" << std::endl;
	if (success() == true)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
}

bool RobotomyRequestForm::success(void) const
{	
	return (std::rand() % 2 == 0);
	
}

