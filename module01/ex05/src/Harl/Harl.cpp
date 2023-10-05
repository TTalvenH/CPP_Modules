#include <Harl.hpp>
 
void	Harl::debug( void ){
	std::cout << "I like bacoooon" << std::endl;
}
void	Harl::info( void ){
	std::cout << "there is not enough bacoooonn" << std::endl;
}
void	Harl::warning( void ){
	std::cout << "i deserve more bacooooon!" << std::endl;
}
void	Harl::error( void ){
	std::cout << "MANAGEEEEEEEER!!!" << std::endl;
}

void	Harl::complain( std::string level ){
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void		(Harl::*f_ptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*f_ptr[i])();
			return ;
		}
	}
}