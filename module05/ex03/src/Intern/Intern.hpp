#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "../AForm/AForm.hpp"

class Intern{
private:
	AForm*	createShrubberyForm(std::string target);
	AForm*	createRobotomyRequestForm(std::string target);
	AForm*	createPresidentialPardonForm(std::string target);
public:
	Intern();
	Intern(const Intern& copy);
	Intern(std::string name, int signGrade, int execGrade);
	Intern&	operator=(const Intern& other);
	~Intern();	

	AForm*	makeForm(std::string name, std::string target);
};

#endif