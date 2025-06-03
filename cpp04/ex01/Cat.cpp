/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:51:23 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/05 11:07:08 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal()
{
	this->_brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat( const Cat& copy): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*(copy.getBrain()));
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Assignation operator called" << std::endl;

	if (this != &other)
		this->_type = other.getType();
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*(other.getBrain()));
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
	return ;
}

void Cat::makeSound() const 
{
	std::cout << "Meow" << std::endl;
	return ;
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}

void	Cat::getIdeas(void) const
{
	for(int i = 0; i < 3; i++)
		std::cout << this->_brain->getIdeas(i) << std::endl;}

void	Cat::setIdeas(size_t i, std::string idea)
{
	this->_brain->setIdea(i , idea);
}