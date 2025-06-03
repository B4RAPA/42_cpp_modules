/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:02:25 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 14:02:16 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	this->_ideas = new std::string[100];
	std::cout << "Brain Default Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = "Something";
	}
	return ;
}

Brain::Brain( const Brain& copy)
{
	std::cout << "Brain copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=( const Brain& other)
{
	std::cout << "Brain Assignation Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	delete [] (this->_ideas);
	std::cout << "Default Destructor called" << std::endl;
}

const std::string Brain::getIdeas(size_t i)const
{
	if ( i < 100)
		return (this->_ideas[i]);
	return ("Only got 100 ideas");
}

void Brain::setIdea(size_t i , std::string& idea)
{
	if ( i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "No space for new Ideas" << std::endl;
}