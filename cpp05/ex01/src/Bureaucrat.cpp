/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:17:04 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/30 11:25:05 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bernd")
{
	std::cout << "Default constructor called" << std::endl;
	this->_grade = 150;

}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	std::cout << "Parametrized Constructor called" << std::endl;
	try{
		checkGrade(grade);
		this->_grade = grade;
	} catch ( const GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	} catch ( const GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Assignation operator called" << std::endl;
	try{
		checkGrade(other._grade);
		this->_grade = other.getGrade();
	} catch ( const GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	} catch ( const GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what()<< std::endl;
	}
	return(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Copy constructor for Bureaucrat called" << std::endl;
	*this = copy;
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << " , bureaucrat grade " << other.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int 	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::checkGrade(int i)
{
	if (i > 150)
		throw GradeTooLowException();
	else if (i <= 0)
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(int i)
{
	int j = getGrade() + i;
	try {
		checkGrade(j);
		this->_grade = j;
		std::cout << "Grade decreased by " << i << std::endl;
	}
	catch ( const Bureaucrat::GradeTooHighException& e){
		std::cout << "Decrease Exception caught: " << e.what() << std::endl;	
	}
	catch ( const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Decrease Exception caught: " << e.what() << std::endl;
	}
}

void Bureaucrat::increaseGrade(int i)
{
	int j = getGrade() - i;
	try {
		checkGrade(j);
		this->_grade = j;
		std::cout << "Grade increased by " << i << std::endl;
	}
	catch ( const Bureaucrat::GradeTooHighException& e){
		std::cout << "Increase Exception caught: " << e.what() << std::endl;	
	}
	catch ( const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Increase Exception caught: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is less than 150");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is higher than 1");
}

const char* Bureaucrat::GradeInsufficentException::what() const throw(){
	return ("Grade is insufficent");
}


void Bureaucrat::signForm(Form &form)
{
	try{
		form.beSigned(*this);
	}
	catch (const Bureaucrat::GradeInsufficentException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() 
			<< " because " << e.what() << std::endl;
	}
}