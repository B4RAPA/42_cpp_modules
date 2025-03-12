#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_Name = "Nobody";
	this->_type = "DiamondTrap";
	this->_ad = 30;
	this->_ep = 50 ;
	this->_hp = 100;
	std::cout << "DiamondTrap default constructor called " << std::endl;
}

DiamondTrap::DiamondTrap( std::string name)
{
	ClapTrap::_Name = name + "_clap_name";
	this->_Name = name;
	this->_type = "DiamondTrap";
	this->_ad = 30;
	this->_ep = 50;
	this->_hp = 100;
	std::cout << "DiamondTrap name constructor called " << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &copy)
{
	this->_Name = copy._Name;
	this->_type = copy._type;
	this->_ad = copy._ad;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap other)
{
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	DiamondTrap::swap(*this, other);
	return (*this);
}

void DiamondTrap::swap( DiamondTrap& first, DiamondTrap& second)
{
	std::swap(first._Name, second._Name);
	std::swap(first._ep, second._ep);
	std::swap(first._ad, second._ad);
	std::swap(first._hp, second._hp);
	std::swap(first._type, second._type);
}

void DiamondTrap::attack( std::string target)
{
	ScavTrap::attack( target);
}

void DiamondTrap::attack( ClapTrap& target)
{
	ScavTrap::attack( target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_Name << " has been mined" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << this->_Name
			  << " "
			  << "Type: " << this->_type
			  << std::endl;
}