
#pragma once
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public virtual  ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string Name );
	~ScavTrap( void );
	ScavTrap( const ScavTrap &other);
	void swap(ScavTrap& first, ScavTrap& second);
	ScavTrap& operator=(ScavTrap other);
	void attack(const std::string &target);
	void attack(ClapTrap &target);
	void guardGate( void );
};