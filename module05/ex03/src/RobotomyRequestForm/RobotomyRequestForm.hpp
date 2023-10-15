#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string m_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

protected:
	void	action() const;
};

#endif