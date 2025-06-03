/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:25:17 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/02 12:49:09 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <iostream>
#include "MutantStack.tpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Current top(before pop): " << mstack.top() << std::endl;
	std::cout << "Current size(before pop): " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Current top(after pop): " << mstack.top() << std::endl;
	std::cout << "Current size(after pop): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	// return (0);

	std::cout << '\n' <<  std::endl;
	MutantStack<int> mystack;
	for( int i = 0; i < 5; ++i)
	{
		mystack.push(i);
	}
	MutantStack<int>::iterator it2 = mystack.begin();
	MutantStack<int>::iterator ite2 = mystack.end();
	std::cout << "Elements:" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << " " << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';


	std::cout << "std::list instead of Stack." << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Current top(before pop): " << list.back() << std::endl;
	std::cout << "Current size(before pop): " << list.size() << std::endl;
	list.pop_back();
	std::cout << "Current top(after pop): " << list.back() << std::endl;
	std::cout << "Current size(after pop): " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it3 = list.begin();
	std::list<int>::iterator ite3 = list.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	return (0);
}