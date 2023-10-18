#include "./Bureaucrat/Bureaucrat.hpp"

int	main(){
	try{
	Bureaucrat Bob("Bob", 1);
	Bureaucrat Timmy("Timmy", 1);

	std::cout << Bob << std::endl;
	std::cout << Timmy << std::endl;

	std::cout << Bob << std::endl;

	for (int i = 0; i < 5; i++)
		Bob.decrementGrade();

	std::cout << Bob << std::endl;

	for (int i = 0; i < 5; i++)
		Bob.incrementGrade();

	std::cout << Bob << std::endl;

	Bob.incrementGrade();

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}