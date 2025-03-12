#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap rudi = ScavTrap("Rudi");
	ScavTrap bernd = ScavTrap("Bernd");
	ClapTrap werner = ClapTrap("Werner");
	FragTrap renate = FragTrap("Renate");

	std::cout << std::endl;
	bernd.status();
	rudi.status();
	werner.status();
	renate.status();
	std::cout << std::endl;
	rudi.guardGate();

	rudi.attack(werner);
	bernd.attack(werner);
	bernd.attack(werner);
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
	std::cout << std::endl;
	return (0);
}