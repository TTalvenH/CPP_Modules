#include "./Bureaucrat/Bureaucrat.hpp"

int	main(){
	try{
	Bureaucrat Default;
	Bureaucrat Bob("Bob", 150);
	Bureaucrat Timmy("Timmy", 1);
	Bureaucrat TimmyCopy(Timmy);


	std::cout << Default << std::endl;
	std::cout << Bob << std::endl;
	std::cout << Timmy << std::endl;
	std::cout << TimmyCopy << std::endl;

	Bob = Timmy;

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