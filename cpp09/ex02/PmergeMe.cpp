/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:01:30 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/16 15:29:22 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


size_t PmergeMe::get_jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (get_jacobsthal(n - 1) + 2 * get_jacobsthal(n - 2));
}

PmergeMe::PmergeMe() : order(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) { (void) copy;};

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}
