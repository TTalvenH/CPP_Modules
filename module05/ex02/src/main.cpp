#include "./Bureaucrat/Bureaucrat.hpp"
#include "./ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm/PresidentialPardonForm.hpp"


int	main(){
	try {
		Bureaucrat Steven("Steven", 150);
		ShrubberyCreationForm SForm("Home"); // sign : 145, exec 137
		RobotomyRequestForm RForm("Nikki"); // sign : 72, exec 45
		PresidentialPardonForm PForm("Donald Duck"); // sign : 25, exec 5

		Steven.signForm(PForm);
		Steven.executeForm(PForm);

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}