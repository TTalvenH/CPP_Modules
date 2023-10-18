#include "./Bureaucrat/Bureaucrat.hpp"
#include "./ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./Intern/Intern.hpp"

int	main(){
	{
	Bureaucrat Steven("Steven", 50);
	Intern someRandomIntern;
	AForm* someForm;
	someForm = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");

	if (someForm){
	Steven.signForm(*someForm);
	Steven.executeForm(*someForm);
	}

	}
}