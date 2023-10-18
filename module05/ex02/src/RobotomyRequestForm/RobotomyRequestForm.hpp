#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string m_target;
	
	RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	virtual ~RobotomyRequestForm();

protected:
	void	action() const;
};

#endif