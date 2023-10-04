#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	m_name;

	public:
		Zombie( std::string name );
		void announce( void );
		~Zombie();
};

void	randomChump( std::string name);
Zombie*	newZombie( std::string name );

#endif
