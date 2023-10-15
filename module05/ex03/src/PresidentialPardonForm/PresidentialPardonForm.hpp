#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string m_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

protected:
	void	action() const;
};

#endif