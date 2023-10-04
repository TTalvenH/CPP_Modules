#include <Zombie.hpp>

int	main( void )
{
	int N = 0;
	Zombie* Horde = zombieHorde(N, "Zombie");
	for(int i = 0; i < N; i++)
		Horde[i].announce();
	delete[] Horde;
}