#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ScavTrap rudi = ScavTrap("Rudi");
	ScavTrap bernd = ScavTrap("Bernd");
	ClapTrap werner = ClapTrap("Werner");
	FragTrap renate = FragTrap("Renate");
	DiamondTrap wilfried = DiamondTrap("Wilfried");
	std::cout << std::endl;
	bernd.status();
	rudi.status();
	wilfried.status();
	werner.status();
	renate.status();
	std::cout << std::endl;
	rudi.guardGate();

	rudi.attack(werner);
	bernd.attack(werner);
	bernd.attack(werner);
	wilfried.attack(werner);
	std::cout << std::endl;
	bernd.status();
	rudi.status();
	werner.status();
	std::cout << std::endl;
	werner.wasteep();
	rudi.beRepaired(40);
	werner.beRepaired(20);
	std::cout << std::endl;
	bernd.status();
	rudi.status();
	werner.status();
	renate.highFivesGuys();
	wilfried.whoAmI();
	std::cout << std::endl;
	return (0);
}