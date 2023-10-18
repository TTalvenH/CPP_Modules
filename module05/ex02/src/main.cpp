#include "./Bureaucrat/Bureaucrat.hpp"
#include "./ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm/PresidentialPardonForm.hpp"


int	main(){
	try {
		Bureaucrat Steven("Steven", 1);
		ShrubberyCreationForm SForm("Home"); // sign : 145, exec 137
		RobotomyRequestForm RForm("Bobby"); // sign : 72, exec 45
		PresidentialPardonForm PForm("Donald Duck"); // sign : 25, exec 5

		Steven.signForm(SForm);
		Steven.executeForm(SForm);

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}