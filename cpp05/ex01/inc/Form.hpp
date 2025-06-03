/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:41:54 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/26 15:52:51 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_execute;

public:
	Form();
	Form(const std::string name, const int s, const int e);
	Form( const Form& copy);
	Form& operator=(const Form& other);
	~Form();
	std::string getName() const;
	bool getStatus() const;
	int	getSignGrade() const;
	int	getExecuteGrade() const;
	void checkGrade2(int f, int b);
	void checkGrade(int i);
	void beSigned(const Bureaucrat& other);
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
std::ostream& operator<<(std::ostream& os, const Form& other);