/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:57:45 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/05 11:07:13 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal()
{
	this->_brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog& copy): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*(copy.getBrain()));
}

Dog& Dog::operator=( const Dog& other)
{
	std::cout << "Dog Assignation Operator called" << std::endl;
	if (this != &other)
		_type = other.getType();
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*(other.getBrain()));
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
	return ;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}

void	Dog::getIdeas(void) const
{
	for(int i = 0; i < 3; i++)
		std::cout << this->_brain->getIdeas(i) << std::endl;
}

void	Dog::setIdeas(size_t i, std::string idea)
{
	this->_brain->setIdea(i , idea);
}