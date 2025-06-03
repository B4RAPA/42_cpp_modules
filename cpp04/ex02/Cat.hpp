/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:31:19 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 13:54:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat( const Cat& copy);
	Cat& operator=(const Cat& other);
	~Cat();
	void makeSound() const;
	Brain *getBrain() const;

	void getIdeas(void) const;
	void	setIdeas(size_t i, std::string idea);
};