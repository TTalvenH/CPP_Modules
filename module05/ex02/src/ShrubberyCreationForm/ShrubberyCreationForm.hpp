#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "../AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	std::string m_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();
protected:
	void	action() const;
};

#endif