#pragma once

#include <iostream>

class ClapTrap
{
private:
	ClapTrap( void );

	std::string _Name;
	int 		_hp;
	int			_ep;
	int	const	_ad;

public:
	ClapTrap( std::string Name);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};