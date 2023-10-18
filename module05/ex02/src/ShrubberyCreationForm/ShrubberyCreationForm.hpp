#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "../AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	std::string m_target;
	
	ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

public:
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
protected:
	void	action() const;
};

#endif