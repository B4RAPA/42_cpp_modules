/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:38 by lfabel            #+#    #+#             */
/*   Updated: 2025/03/20 13:43:18 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	
public:
	WrongCat();
	WrongCat( const WrongCat& copy);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();
	void makeSound() const;
};