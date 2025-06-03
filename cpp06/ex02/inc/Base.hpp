/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:34:29 by lfabel            #+#    #+#             */
/*   Updated: 2025/05/27 15:29:37 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdlib.h>
#include <iostream>
#include <ctime>

class Base
{
private:

public:
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
	virtual ~Base();
};