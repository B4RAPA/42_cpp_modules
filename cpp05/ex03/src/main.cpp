/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:57 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 11:35:38 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	std::srand(std::time(0));
	Bureaucrat* Bernd = NULL;
	try{
		Bernd = new Bureaucrat(0, "bernd");
	} catch( Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "construction failed because " << e.what() << std::endl;
	}
	if (Bernd != NULL)
	{
		delete Bernd;
	}
	Bureaucrat* bernd = new Bureaucrat(140, "bernd");
	Bureaucrat* heidi = new Bureaucrat(25, "heidi");
	Intern newIntern;
	AForm	*intern_form;
	PresidentialPardonForm president("Donald");
	ShrubberyCreationForm	shrubby("Werner");
	RobotomyRequestForm		robot("IRobot");



	std::cout << std::endl;
	std::cout << *heidi << std::endl;
	std::cout << *bernd << std::endl;
	std::cout << president << std::endl;
	std::cout << robot << std::endl;
	std::cout << shrubby << std::endl;
	std::cout << std::endl;
	heidi->signForm(robot);
	heidi->signForm(shrubby);
	bernd->signForm(president);
	std::cout << std::endl;
	heidi->executeForm(president);
	heidi->executeForm(shrubby);
	bernd->executeForm(robot);
	heidi->executeForm(robot);
	heidi->executeForm(robot);
	heidi->executeForm(robot);
	std::cout << std::endl;
	heidi->decreaseGrade(200);
	heidi->increaseGrade(20);
	bernd->increaseGrade(136);
	std::cout << std::endl;
	heidi->executeForm(president);
	std::cout << std::endl;	
	std::cout << *heidi << std::endl;
	std::cout << *bernd << std::endl;
	std::cout << std::endl;
	intern_form = newIntern.makeForm("RobotomyRequestForm", "weber");
	if (intern_form == NULL)
		delete intern_form;
	if (intern_form)
		std::cout << *intern_form << std::endl;
	heidi->signForm(*intern_form);
	heidi->executeForm(*intern_form);
	std::cout << std::endl;
	delete heidi;
	delete bernd;
	delete intern_form;
}