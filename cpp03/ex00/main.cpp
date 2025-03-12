#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap newClap("Bernd");
	ClapTrap newClap2("Rudi");
	newClap.attack("Rudi");
	newClap.takeDamage(5);
	newClap.beRepaired(4);
	return (0);
}