#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
protected:

	std::string	_type;
	std::string _Name;
	int 		_hp;
	int			_ep;
	int			_ad;

public:
	ClapTrap( void );
	ClapTrap( std::string Name);
	ClapTrap(const ClapTrap& other);
	void swap(ClapTrap& first, ClapTrap& second);
	ClapTrap& operator=(ClapTrap other);
	void attack(const std::string& target);
	void attack(ClapTrap &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int getHP();
	int getEP();
	int getAD();
	std::string getName() const ;
	void setHP( int const hp );
	void setAD( int const ad );
	void setEP( int const ep );
	void status(void) const;
	void wasteep();
	~ClapTrap();

};