/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:42:25 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/27 16:02:26 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template<typename T>
void swap(T& s, T& i)
{
	T j;
	j = s;
	s = i;
	i = j;	
}

template<typename T>
T min(T& s, T& i)
{
	if (s < i)
		return (s);
	else 
		return (i);
}

template<typename T>
T max(T& s, T& i)
{
	if (s > i)
		return (s);
	else 
		return (i);
}