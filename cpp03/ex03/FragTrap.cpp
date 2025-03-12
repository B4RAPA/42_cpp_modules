#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->_Name = "Nobody";
	this->_type = "FragTrap";
	this->_ad = 30;
	this->_ep = 100;
	this->_hp = 100;
	std::cout << "Default constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap( std::string Name )
{
	this->_Name = Name;
	this->_type = "FragTrap";
	this->_ad = 30;
	this->_ep = 100;
	this->_hp = 100;
	std::cout << "Name Constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other)
{
	this->_Name = other._Name;
	this->_type = other._type;
	this->_ad = other._ad;
	this->_hp = other._hp;
	this->_ep = other._ep;
}


FragTrap::~FragTrap()
{
	std::cout << this->_Name << " was first frag" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap other)
{
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	FragTrap::swap(*this, other);
	return (*this);
}

void FragTrap::swap( FragTrap& first, FragTrap& second)
{
	std::swap(first._Name, second._Name);
	std::swap(first._ep, second._ep);
	std::swap(first._ad, second._ad);
	std::swap(first._hp, second._hp);
	std::swap(first._type, second._type);
}

void FragTrap::attack(const std::string &target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	if (this->_hp > 0)
	{
		this->_ep -= 1;
		std::cout << "FragTrap " << this->_Name << " attacks " << target
			  << " causing " << this->_ad << " points of dmg " << std::endl;
	}
	else
		std::cout << this->_Name << "is already dead and cant attack" << std::endl;
}

void FragTrap::attack(ClapTrap &target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	if (this->_hp > 0)
	{
		this->_ep -= 1;
		std::cout << "FragTrap " << this->_Name << " attacks " << target.getName()
			  << " causing " << this->_ad << " points of dmg " << std::endl;
		target.takeDamage(this->getAD());
	}
	else
		std::cout << this->_Name << "is already dead and cant attack" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << this->_Name << " wants to High Five " << std::endl;
}