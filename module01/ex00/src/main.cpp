#include <Zombie.hpp>

int	main( void )
{
	Zombie* NewZombie = newZombie("Test_zomboi1");
	randomChump("Test_zomboi2");
	delete(NewZombie);
}