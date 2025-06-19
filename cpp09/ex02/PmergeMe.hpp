/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:01:32 by lfabel            #+#    #+#             */
/*   Updated: 2025/06/16 15:29:11 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <math.h>
#include <algorithm>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
	int order;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	template<typename Container>
	void sort(Container &vec);
	size_t get_jacobsthal(int n);
	template<typename Container>
	void insert(Container& main, Container& pend, size_t order, Container &left);
	template<typename Iterator, typename T>
	Iterator block_upper_bound(Iterator begin, Iterator end, const T& val, size_t order);
};

template<typename Container>
void PmergeMe::sort(Container &vec)
{
	typedef typename Container::iterator Iterator;
	
	if (this->order == 0)
	{
		order = 1;
	}
	size_t half = order / 2;

	int leftovers = vec.size() % order;
	if ( order >= 2 && (vec.size() - leftovers) / (order / 2) < 2)
		return;
	Iterator it = vec.begin() + order;
	for (size_t i = 0; i * order < vec.size() - leftovers; ++i)
	{
		Iterator first_start = vec.begin() + i * order;
		Iterator second_start = first_start + half;
		size_t idx1 = (first_start + half - 1) - vec.begin();
		size_t idx2 = (second_start + half - 1) - vec.begin();
		if (idx1 < vec.size() && idx2 < vec.size())
		{
			if (vec.at(idx1) > vec.at(idx2))
			{
				std::swap_ranges(first_start, first_start + half, second_start);
			}
		}
	}
	order *= 2;
	sort(vec);
	order /= 2;

	Container main;
	Container pend;
	Container left; 
	it = vec.begin();
	for (size_t i = 0; i < (vec.size() - leftovers) / order; i++)
	{
		if (i % 2 != 0 || i == 0)
		{
			for (int j = 0; j < order; j++)
			{
				main.push_back(*it);
				++it;
			}
		}
		else
		{
			for (int j = 0; j < order; j++)
			{
				pend.push_back(*it);
				++it;
			}
		}
	}
	it = vec.end()  - leftovers;
	while (it != vec.end())
	{
		left.push_back(*it);
		it++;
	}
	insert(main, pend, order, left);
	vec = main;	
}

template<typename Container>
void PmergeMe::insert(Container& main, Container& pend, size_t order, Container &left)
{
	typedef typename Container::iterator Iterator;
	
	Iterator end;	
	size_t jct = 3;
	size_t count = 0;
	size_t max_inserts = pend.size() / order;
	size_t pend_nb = 0;
	size_t last_count = 0;
	while (count < max_inserts)
	{
		pend_nb = (get_jacobsthal(jct) - 1) * order ;
		while (pend_nb > pend.size())
			pend_nb--;
		while (count < get_jacobsthal(jct) - 1 && count < max_inserts && pend_nb > 0)
		{
			if (get_jacobsthal(jct) * order + (get_jacobsthal(jct) - get_jacobsthal(jct -1) +  (count - last_count)) * order <= main.size())
				end = main.begin() + (get_jacobsthal(jct) * order ) + (get_jacobsthal(jct) - get_jacobsthal(jct -1) +(count - last_count)) * order;
			else
				end = main.end();
			Iterator pos = block_upper_bound(main.begin(), end, pend.at(pend_nb - 1), order);
			main.insert(pos, pend.begin() + pend_nb - order , pend.begin() + pend_nb);
			count++;
			pend_nb -= order;
			last_count = count - last_count;
		}
		jct ++;
	}

	if (left.empty()) {}
	else if (!left.empty())
	{
		main.insert(main.end(), left.begin(), left.end());
	}
	pend.clear();
	left.clear();
}

template<typename Iterator, typename T>
Iterator PmergeMe::block_upper_bound(Iterator begin, Iterator end, const T& val, size_t order)
{
	for (Iterator it = begin; it < end; it += order)
	{
		Iterator block_last = it + order - 1;
		if (block_last >= end)
			block_last = end - 1;

		if (*block_last > val)
			return it;
	}
	return end;
}