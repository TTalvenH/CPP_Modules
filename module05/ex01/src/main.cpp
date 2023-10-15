#include "./Bureaucrat/Bureaucrat.hpp"

int	main(){
	try {
	Form formA("FormA", 50, 150);
	Form formB("FormB", 1, 150);
	std::cout << formA << std::endl;
	std::cout << std::endl;
	std::cout << formB << std::endl;
	std::cout << "\n================================\n" << std::endl;

	Bureaucrat Pekka("Pekka", 50);
	
	Pekka.signForm(formA);
	Pekka.signForm(formB);

	std::cout << "\n================================\n" << std::endl;

	std::cout << formA << std::endl;
	std::cout << std::endl;
	std::cout << formB << std::endl;

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}