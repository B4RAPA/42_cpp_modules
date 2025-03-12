#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void) : _Name("Nobody"), _ad(0), _hp(10), _ep(10)
{
	return ;
}

ClapTrap::ClapTrap( std::string Name ) : _Name("Nobody"), _ad(0), _hp(10), _ep(10)
{
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << "ClapTrap " << this->_Name << " attacks " << target
			  << " causing " << this->_ad << " points of dmg " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap has taken " << amount << " points of dmg " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	this->_ep -= 0;
	std::cout << "ClapTrap has healed for " << amount << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap got trashed" << std::endl;
	return ;
}