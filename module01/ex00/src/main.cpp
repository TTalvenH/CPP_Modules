#include "./Zombie/Zombie.hpp"

int	main( void )
{
	Zombie* NewZombie = newZombie("NewZomboi");
	NewZombie->announce();
	randomChump("RandomZomboi");
	delete(NewZombie);
}