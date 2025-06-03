/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:31 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/02 14:17:20 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class Brain
{
private:
	std::string *_ideas;	
public:
	Brain();
	Brain( const Brain& copy);
	Brain& operator=( const Brain& other);
	~Brain();
	
	const std::string getIdeas(size_t i) const;
	void setIdea(size_t i , std::string& idea);
};