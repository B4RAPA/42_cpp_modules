
#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
	std::string _Name;

public:
	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &other);
	void swap( DiamondTrap& first, DiamondTrap& second);
	DiamondTrap &operator=(DiamondTrap other);
	void attack( std::string target);
	void attack( ClapTrap& target);
	~DiamondTrap();
	void whoAmI();
};