#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5)
, m_target("default"){}
 
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy.getName(), copy.getSigned(), copy.getExecGrade())
, m_target(copy.m_target){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
, m_target(target){}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		std::cout << "this is dum don't do this" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::action() const{
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}