#include "Intern.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

AForm*	Intern::createShrubberyForm(std::string target){ return new ShrubberyCreationForm(target); }
AForm*	Intern::createRobotomyRequestForm(std::string target){ return new RobotomyRequestForm(target); }
AForm*	Intern::createPresidentialPardonForm(std::string target){ return new PresidentialPardonForm(target); }

AForm*	Intern::makeForm( std::string name, std::string target) {
	std::string	forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm* (Intern::*f_ptr[3])(std::string target) = { &Intern::createShrubberyForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	for (int i = 0; i < 3; i++){
		if (name == forms[i]){
			std::cout << "Intern creates " << name << std::endl;
			return (this->*f_ptr[i])(target);
		}
	}
	std::cout << "Intern couldn't create the form!" << std::endl;
	return NULL;
}