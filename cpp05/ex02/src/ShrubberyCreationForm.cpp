/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:14:17 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:24:23 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubbyCreationForm", 145, 137), _target("default")
{
	std::cout << "Default constructor for ShrubberyCreationForm has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubbyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parametrized constructor for ShrubberyCreationForm has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	std::cout << "Copy Constructor for ShrubberyCreationForm has been called" << std::endl;	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Assignation operator for ShrubberyCreationForm has been called" << std::endl;	
	if (this != &other)
		*this = other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for ShrubberyCreationForm has been called" << std::endl;
}

void ShrubberyCreationForm::performAction() const
{
	std::cout << "The Form " << this->_target << " has been created" << std::endl;
	printTree(this->_target);
}

void ShrubberyCreationForm::printTree(const std::string target) const
{
	std::string file; //dunno about the ascii file
	file = target + "_shrubbery";
	std::ofstream myfile(file.c_str());
    myfile << "        *        \n";
    myfile << "       ***       \n";
    myfile << "      *****      \n";
    myfile << "     *******     \n";
    myfile << "    *********    \n";
    myfile << "   ***********   \n";
    myfile << "  *************  \n";
    myfile << " *************** \n";
    myfile << "*****************\n";
    myfile << "       |||       \n";
    myfile << "       |||       \n";
	myfile.close();
}