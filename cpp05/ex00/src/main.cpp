/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:57 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/30 11:15:19 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat* Bernd = NULL;
	try{
	Bernd = new Bureaucrat(0, "bernd");
	} catch( Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Construction failed because " << e.what() << std::endl;
	}  catch( Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Construction failed because " << e.what() << std::endl;
	}
	if (Bernd != NULL)
	{
		delete Bernd;
	}

	Bureaucrat* bernd = new Bureaucrat(200, "bernd");
	Bureaucrat* heidi = new Bureaucrat(25, "heidi");
	std::cout << *heidi << std::endl;
	heidi->decreaseGrade(200);
	std::cout << *heidi << std::endl;
	heidi->increaseGrade(10);
	std::cout << *heidi << std::endl;
	std::cout << *bernd << std::endl;
	bernd->increaseGrade(149);
	std::cout << *bernd << std::endl;
	delete heidi;
	delete bernd;
}