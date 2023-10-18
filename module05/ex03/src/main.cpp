#include "./Bureaucrat/Bureaucrat.hpp"
#include "./ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./Intern/Intern.hpp"

int	main(){
	{
	Bureaucrat Steven("Steven", 150);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

	if (rrf){
	Steven.signForm(*rrf);
	}

	}
}