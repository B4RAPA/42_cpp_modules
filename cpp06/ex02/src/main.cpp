/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:44:27 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 15:08:17 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"


int main()
{
	Base* base = NULL;
	std::srand(std::time(0));
	base = base->generate();
	base->identify(base);
	base->identify(*base);
	base = base->generate();
	base->identify(base);
	base->identify(*base);
}

Base*	Base::generate(void)
{
	if (std::rand() % 3 == 0)
	{
		return (new A);
	}
	else if( std::rand() % 3 == 1)
		return (new B);
	else 
		return (new C);
}

void Base::identify(Base* p)
{
	if ( dynamic_cast<A*>(p))
		std::cout << "Its a" << std::endl;
	else if ( dynamic_cast<B*>(p))
		std::cout << "Its b" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Its c" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Its a" << std::endl;
		(void)a;
		return;
	}catch(...){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Its b" << std::endl;
		(void)b;
		return;
	}catch(...){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Its c" << std::endl;
		(void)c;
		return;
	}catch(...){}
	std::cout << "Unknown type" << std::endl;
}