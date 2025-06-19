/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:24 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/04 12:37:12 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <cctype>
#include <string>
#include <iostream>

class RPN
{
private:
	std::stack<int> _mystack;
public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN();

	void calc(char **argv);
	int getTop() const;
};