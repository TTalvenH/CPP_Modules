#include "Harl.hpp"
 
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
	int i = 0;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// void		(Harl::*f_ptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for ( ; i < 4; i++){
		if (level == levels[i]){
			break;
		}
	}
	// for ( ; i < 4 ; i++){
	// 	(this->*f_ptr[i])();
	// }
	switch(i){
		case 0:
			debug(); info(); warning(); error();
			break;
		case 1:
			info(); warning(); error();
			break;
		case 2:
			warning(); error();
			break;
		case 3:
			error();
			break;
	}
}