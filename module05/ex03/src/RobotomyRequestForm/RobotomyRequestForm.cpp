#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
, m_target("default"){}
 
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy.getName(), copy.getSigned(), copy.getExecGrade())
, m_target(copy.m_target){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
, m_target(target){}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		std::cout << "this is dum don't do this" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::action() const{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	int	randomValue = std::rand() % 2;
	std::cout << "Brrrrrrrrrrrrrrrr..." << std::endl;
	if (randomValue){
		std::cout << m_target << " was successfully robotomized!" << std::endl;
	} 
	else{
		std::cout << "Robotomy failed!" << std::endl;
	}

}