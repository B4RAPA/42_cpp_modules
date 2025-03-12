#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void) : _Name("Nobody"), _type("ClapTrap"), _ad(20), _hp(100), _ep(50)
{
	std::cout << "Default Constructor for ClapTrap called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string Name ) : _Name(Name), _type("ClapTrap"), _ad(20), _hp(100), _ep(50)
{
	std::cout << "Name Constructor for ClapTrap called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( const ClapTrap &other)
{
	this->_Name = other._Name;
	this->_type = other._type;
	this->_ad = other._ad;
	this->_hp = other._hp;
	this->_ep = other._ep;
}

ClapTrap &ClapTrap::operator=(ClapTrap other)
{
	std::cout << "Copy constructor of ClapTrap called" << std::endl;
	ClapTrap::swap(*this, other);
	return (*this);
}

void ClapTrap::swap( ClapTrap& first, ClapTrap& second)
{
	std::swap(first._Name, second._Name);
	std::swap(first._ep, second._ep);
	std::swap(first._ad, second._ad);
	std::swap(first._hp, second._hp);
	std::swap(first._type, second._type);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep == 0)
	{
		std::cout << "No energy" << std::endl;
		return ;
	}
	this->_ep -= 1;
	std::cout << this->_type << " " << this->_Name << " attacks " << target
			  << " causing " << this->_ad << " points of dmg " << std::endl;
}

void ClapTrap::attack(ClapTrap &target)
{
	if (this->_ep <= 0)
	{
		std::cout << this->_Name <<  "has not enough energy for an attack" << std::endl;
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		std::cout << this->_Name <<  " has taken " << amount << " points of dmg " << std::endl;
		setHP( getHP() - amount);
		if (this->_hp <= 0)
			std::cout << this->_Name << " and died" << std::endl;
	}
	else
		std::cout << this->_Name << "is already dead and cant take anymore dmg" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep == 0)
	{
		std::cout << this->_Name << "has not enough energy for repair" << std::endl;
		return ;
	}
	this->_ep--;
	this->_hp = getHP() + amount; 
	std::cout << this->_Name <<  " has healed for " << amount << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_Name << " ClapTrap got clapped" << std::endl;
	return ;
}

int ClapTrap::getAD()
{
	return (this->_ad);
}


int ClapTrap::getHP()
{
	return (this->_hp);
}

int ClapTrap::getEP()
{
	return (this->_ep);
}

std::string ClapTrap::getName() const
{
	return (this->_Name);
}

void ClapTrap::setHP(int const hp)
{
	this->_hp = hp;
}

void ClapTrap::setEP(int const ep)
{
	this->_ep = ep;
}

void ClapTrap::setAD(int const ad)
{
	this->_ad = ad;
}

void ClapTrap::status(void) const
{
	std::cout << this->_Name
	<< " " << this->_type
	<< " has " << this->_hp << " Health Points"
	<< " has " << this->_ad << " Attack Damage"
	<< " has " << this->_ep << " Energy Points"
	<< std::endl;
}


void ClapTrap::wasteep()
{
	this->_ep = 0;
	return ;
}