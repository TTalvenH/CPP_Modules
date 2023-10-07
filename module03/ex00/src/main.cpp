#include <ClapTrap.hpp>

int main (){
	ClapTrap	Nameless;
	ClapTrap	Buck("Buck");
	ClapTrap	Bob("Bob");

	ClapTrap	Bob2(Bob);
	
	std::cout << std::endl;
	Buck.attack("Bob");
	Bob.attack("Buck");
	Bob2.attack("Buck");
	std::cout << std::endl;
	
	Bob2 = Buck;
	Bob2.attack("Buck");

	Buck.takeDamage(5);
	Buck.beRepaired(5);

	Buck.takeDamage(5);
	Buck.takeDamage(5);
	Buck.attack("No hp to attack");

	ClapTrap	Energy("Energy");

	for (int i = 10; i != 0; i--)
		Energy.attack("test");
	Energy.beRepaired(10);
}