/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:41:52 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:20:18 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _grade_sign(150), _grade_execute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int s, int e) : _name(name), _signed(false), _grade_sign(s), _grade_execute(e)
{
	std::cout << "Parametrized Constructor called" << std::endl;	
	try {
		checkGrade(s);
		checkGrade(e);	
	} catch ( const AForm::GradeTooHighException& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
	catch ( const AForm::GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
}

AForm::AForm( const AForm& copy) : _name(copy._name) , _signed(false), _grade_sign(copy._grade_sign) ,_grade_execute(copy._grade_execute)
{	
	std::cout << "Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_signed = other._signed;
	return(*this);
}

void AForm::beSigned(const Bureaucrat& other)
{
	try {
		checkGrade2(this->getSignGrade(), other.getGrade());
		if (this->getStatus() != true)
		{
			this->_signed = true;
			std::cout << other.getName() << " signed " << this->getName() << std::endl;	
			return;
		}
		std::cout << "Form is already signed" << std::endl;
	}  catch ( const GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	} catch ( const GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw Bureaucrat::GradeInsufficentException();
	} catch ( const GradeInsufficentException& e) {
		std::cout << "Exception caught: " << e.what() << " to sign" << std::endl;
		throw Bureaucrat::GradeInsufficentException();
	}
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getStatus() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const
{
	return (this->_grade_sign);
}

int	AForm::getExecuteGrade() const
{
	return (this->_grade_execute);	
}

void AForm::checkGrade(int i)
{
	if (i > 150)
		throw GradeTooLowException();
	else if (i <= 0)
		throw GradeTooHighException();
}

void AForm::checkGrade2(int f, int b) const
{
	if (f > 150 || b > 150)
		throw GradeTooLowException();
	else if (f <= 0 || b <= 0)
		throw GradeTooHighException();
	else if (b > f)
		throw GradeInsufficentException();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is less than 150");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is higher than 1");
}

const char* AForm::GradeInsufficentException::what() const throw(){
	return ("Grade is insufficent");
}

std::ostream& operator<< (std::ostream& os, const AForm& other)
{
	os << other.getName() << " , AForm grade " << other.getSignGrade();
	return (os);
}

void AForm::execute(Bureaucrat const& executor) const
{
	try{
		checkGrade2(this->getExecuteGrade(), executor.getGrade());
		this->performAction();
	} catch ( const GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	} catch ( const GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what()<< std::endl;
	} catch ( const GradeInsufficentException& e) {
		std::cout << "Exception caught: " << e.what()<< std::endl;
		throw;
	}
}