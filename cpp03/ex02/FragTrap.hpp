
#pragma once
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( const FragTrap &other);
	void attack(const std::string &target);
	void attack(ClapTrap &target);
	FragTrap &operator=(FragTrap other);
	void swap( FragTrap& first, FragTrap& second);
	~FragTrap();
	void highFivesGuys( void );
};