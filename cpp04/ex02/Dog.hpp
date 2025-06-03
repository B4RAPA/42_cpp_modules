/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:30:57 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 14:03:58 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog( const Dog& copy);
	Dog& operator=( const Dog& other);
	~Dog();
	void makeSound() const;
	Brain *getBrain() const;

	void getIdeas(void) const;
	void	setIdeas(size_t i, std::string idea);
};