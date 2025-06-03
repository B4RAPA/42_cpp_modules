/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:22:52 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/26 15:29:10 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name ;
	int					_grade;
public:

	Bureaucrat();
	Bureaucrat(int grade, std::string name);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	std::string getName() const;
	int	getGrade() const;
	void increaseGrade(int i);
	void decreaseGrade(int i);
	void checkGrade(int i);
	void signForm(Form &form);
	class  GradeTooHighException : public std::exception {
		public:
		GradeTooHighException() {}
		virtual const char* what() const throw();
		
	};
	class GradeTooLowException : public std::exception {
		public:
		GradeTooLowException() {}
		virtual const char* what() const throw();
	};
	class GradeInsufficentException : public std::exception {
		public:
		GradeInsufficentException() {}
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);