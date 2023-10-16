#include "./FragTrap/FragTrap.hpp"
#include "./ScavTrap/ScavTrap.hpp"

int main (){
	ClapTrap clappi("Clappi");
	ScavTrap scav("Scavvi");

	clappi.attack("Scavvi");
	scav.attack("Clappi");
	scav.beRepaired(10);
	scav.takeDamage(10);
    scav.guardGate();

	std::cout << "\n===========================\n" << std::endl;

	ScavTrap scav_copy(scav);
	ScavTrap scav2("newScavvi");

	scav_copy.attack("someone");

	scav_copy = scav2;

	scav_copy.attack("someone");

	std::cout << "\n===========================\n" << std::endl;

	FragTrap fraggy("Fraggy");

	fraggy.highFiveGuys();
}