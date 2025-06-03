/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:57 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/28 11:30:50 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
int main(void)
{

	Bureaucrat* Bernd = NULL;
	try{
		Bernd = new Bureaucrat(0, "bernd");
	} catch( Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Construction for Bureaucrat failed because " << e.what() << std::endl;
	}
	if (Bernd != NULL)
	{
		delete Bernd;
	}
	Bureaucrat* Willhelm = NULL;
	try{
		Willhelm = new Bureaucrat(200, "willhelm");
	} catch( Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Construction for Bureaucrat failed because " << e.what() << std::endl;
	}
	if (Willhelm != NULL)
	{
		delete Willhelm;
	}
	
	Bureaucrat* bernd = new Bureaucrat(140, "bernd");
	Bureaucrat* heidi = new Bureaucrat(25, "heidi");
	Form	*ab2 = new Form("ab2", 27, 27);

	std::cout << "\n" <<  "Check init" << std::endl;
	std::cout << *heidi << std::endl;	
	std::cout << *ab2 << std::endl;
	std::cout << *bernd << std::endl;

	std::cout << "\n" << "Check Signing" << std::endl;
	heidi->signForm(*ab2);
	bernd->signForm(*ab2);
	heidi->signForm(*ab2);
	heidi->decreaseGrade(200);
	std::cout << "\n" << "Check after failed decrease" << std::endl;
	std::cout << *heidi << std::endl;
	delete ab2;

	std::cout << "\n" << "Check for cant sign Form" << std::endl;
	Form *ab1 = new Form("ab1", 1, 1);
	Form *invalid = NULL;
	try {
		invalid = new Form("invalid", 160, 170);
	}  catch( Form::GradeTooHighException& e)
	{
		std::cout << "Construction for Form failed because " << e.what() << std::endl;
	} catch( Form::GradeTooLowException& e)
	{
		std::cout << "Construction for Form failed because " << e.what() << std::endl;
	} if (invalid == NULL)
	{
		delete invalid;
	}
	std::cout << *ab1 << std::endl;
	heidi->signForm(*ab1);
	delete heidi;
	delete bernd;
	delete ab1;
}