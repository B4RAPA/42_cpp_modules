/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:30:29 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/05 11:06:46 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	Cat *bruno = new Cat;
	Dog *Werner = new Dog;

	std::cout << std::endl;
	std::cout << "Animal j is type " <<  j->getType() << " " << std::endl;
	std::cout << "Animal i is type " << i->getType() << " " << std::endl;
	std::cout << "Animal a is type " << a->getType() << " " << std::endl;
	std::cout << "Animal b is type " << b->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	b->makeSound();
	a->makeSound();
	std::cout << std::endl;
	bruno->setIdeas(1, "sniff");
	bruno->getIdeas();
	std::cout << std::endl;
	Werner->setIdeas(0, "I want to go for a Walk");
	Werner->setIdeas(1, "I want some food");
	Werner->setIdeas(2, "throw the stick");
	Werner->getIdeas();
	std::cout << std::endl;
	delete(j);
	delete(i);
	delete(b);
	delete(a);
	delete(Werner);
	delete(bruno);
	return (0);
}