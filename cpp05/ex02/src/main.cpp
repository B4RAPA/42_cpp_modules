/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:57 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 11:33:25 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

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
	PresidentialPardonForm	*president = new PresidentialPardonForm("Donald");
	ShrubberyCreationForm	*shrubby = new ShrubberyCreationForm("Werner");
	RobotomyRequestForm		*robot	 = new RobotomyRequestForm("IRobot");

	std::cout << std::endl;
	std::cout << *heidi << std::endl;
	std::cout << *bernd << std::endl;
	std::cout << *president << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *shrubby << std::endl;
	std::cout << std::endl;
	heidi->signForm(*robot);
	heidi->signForm(*shrubby);
	bernd->signForm(*shrubby);
	std::cout << std::endl;
	bernd->executeForm(*president);
	heidi->executeForm(*shrubby);
	bernd->executeForm(*robot);
	heidi->executeForm(*robot);
	heidi->executeForm(*robot);
	heidi->executeForm(*robot);
	std::cout << std::endl;
	heidi->decreaseGrade(200);
	heidi->increaseGrade(20);
	bernd->increaseGrade(136);
	std::cout << std::endl;
	heidi->executeForm(*president);
	std::cout << std::endl;	
	std::cout << *heidi << std::endl;
	std::cout << *bernd << std::endl;
	std::cout << std::endl;	
	delete heidi;
	delete bernd;
	delete president;
	delete shrubby;
	delete robot;
}