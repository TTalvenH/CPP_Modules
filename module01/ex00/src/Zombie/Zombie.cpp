#include <Zombie.hpp>

Zombie::Zombie( std::string name ) : m_name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << m_name << " Destroyeeeed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}