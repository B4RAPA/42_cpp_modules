/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:14:48 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/03 09:56:01 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

template<typename T >
class MutantStack : public std::stack<T>
{
private:

public:
MutantStack();
MutantStack(const MutantStack& copy);
MutantStack& operator=(const MutantStack& other);
~MutantStack() {};

typedef typename std::stack<T>::container_type::iterator iterator;
typedef typename std::stack<T>::container_type::const_iterator const_iterator;
typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

iterator begin();
iterator end();
const_iterator const_begin();
const_iterator const_end();
reverse_iterator reverse_begin();
reverse_iterator reverse_end();
const_reverse_iterator const_reverse_begin();
const_reverse_iterator const_reverse_end();
};
