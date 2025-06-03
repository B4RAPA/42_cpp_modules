/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:41:52 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:21:32 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _grade_sign(150), _grade_execute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, int s, int e) : _name(name), _signed(false), _grade_sign(s), _grade_execute(e)
{
	std::cout << "Parametrized Constructor called" << std::endl;	
	try {
		checkGrade(s);
		checkGrade(e);	
	} catch ( const Form::GradeTooHighException& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
	catch ( const Form::GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		throw;
	}
}

Form::Form( const Form& copy) : _name(copy._name) , _signed(false), _grade_sign(copy._grade_sign) ,_grade_execute(copy._grade_execute)
{	
	std::cout << "Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Assigment operator called" << std::endl;
	this->_signed = other._signed;
	return(*this);
}

void Form::beSigned(const Bureaucrat& other)
{
	try {
		checkGrade2(this->getSignGrade(), other.getGrade());
		if (this->getStatus() != true)
		{
			this->_signed = true;
			std::cout << other.getName() << " signed " << this->getName() << std::endl;	
			return;
		}
		std::cout << "Form " << this->_name <<  " is already signed" << std::endl;
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

Form::~Form()
{
	std::cout << "Destructor for Form called" << std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getStatus() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_grade_sign);
}

int	Form::getExecuteGrade() const
{
	return (this->_grade_execute);	
}

void Form::checkGrade(int i)
{
	if (i > 150)
		throw GradeTooLowException();
	else if (i <= 0)
		throw GradeTooHighException();
}

void Form::checkGrade2(int f, int b)
{
	if (f > 150 || b > 150)
		throw GradeTooLowException();
	else if (f <= 0 || b <= 0)
		throw GradeTooHighException();
	else if (b > f)
		throw GradeInsufficentException();
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is less than 150");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is higher than 1");
}

const char* Form::GradeInsufficentException::what() const throw(){
	return ("Grade is insufficent");
}

std::ostream& operator<< (std::ostream& os, const Form& other)
{
	os << other.getName() << " , Form grade " << other.getSignGrade();
	return (os);
}
