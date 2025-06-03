/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:41:54 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/26 16:09:52 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_execute;
	virtual void performAction() const = 0;

public:
	AForm();
	AForm(const std::string name, const int s, const int e);
	AForm( const AForm& copy);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	std::string getName() const;
	bool getStatus() const;
	int	getSignGrade() const;
	int	getExecuteGrade() const;
	void checkGrade2(int f, int b) const;
	void checkGrade(int i);
	void beSigned(const Bureaucrat& other);
	void execute(Bureaucrat const& executor) const;
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
std::ostream& operator<<(std::ostream& os, const AForm& other);