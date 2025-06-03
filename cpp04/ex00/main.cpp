/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:30:29 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/20 13:46:08 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();

	std::cout << "Animal j is type " <<  j->getType() << " " << std::endl;
	std::cout << "Animal i is type " << i->getType() << " " << std::endl;
	std::cout << "Animal meta is type " << meta->getType() << " " << std::endl;
	std::cout << "Animal a is type " << a->getType() << " " << std::endl;
	std::cout << "Animal b is type " << b->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	b->makeSound();
	a->makeSound();
	meta->makeSound();

	delete(j);
	delete(i);
	delete(b);
	delete(a);
	delete(meta);
	return (0);
}