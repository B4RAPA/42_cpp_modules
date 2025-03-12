#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	this->_Name = "Nobody";
	this->_type = "ScavTrap";
	this->_ad = 20;
	this->_ep = 50;
	this->_hp = 100;
	std::cout << "Default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( std::string Name )
{
	this->_Name = Name;
	this->_type = "ScavTrap";
	this->_ad = 20;
	this->_ep = 50;
	this->_hp = 100;
	std::cout << "Name Constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other)
{
	this->_Name = other._Name;
	this->_type = other._type;
	this->_ad = other._ad;
	this->_hp = other._hp;
	this->_ep = other._ep;
}

ScavTrap &ScavTrap::operator=(ScavTrap other)
{
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	ScavTrap::swap(*this, other);
	return (*this);
}

void ScavTrap::swap( ScavTrap& first, ScavTrap& second)
{
	std::swap(first._Name, second._Name);
	std::swap(first._ep, second._ep);
	std::swap(first._ad, second._ad);
	std::swap(first._hp, second._hp);
	std::swap(first._type, second._type);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	if (this->_hp > 0)
	{
		this->_ep -= 1;
		std::cout << this->_type << " " << this->_Name << " attacks " << target
			  << " causing " << this->_ad << " points of dmg " << std::endl;
	}
	else
		std::cout << this->_Name << "is already dead and cant attack" << std::endl;
}

void ScavTrap::attack(ClapTrap &target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	if (this->_hp > 0)
	{
		this->_ep -= 1;
		std::cout << this->_type << " " << this->_Name << " attacks " << target.getName()
			  << " causing " << this->_ad << " points of dmg " << std::endl;
		target.takeDamage(this->getAD());
	}
	else
		std::cout << this->_Name << "is already dead and cant attack" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_Name << " ScavTrap got scavenged" << std::endl;
	return ;
}

void ScavTrap::guardGate(void)
{
	if (this->_ep <= 0)
		std::cout << this->_Name << " has not enought Energy for Gatekeeper" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_Name << " is now in Gate Keeper Mode" << std::endl;
		this->_ep--;
	}
	return ;
}
