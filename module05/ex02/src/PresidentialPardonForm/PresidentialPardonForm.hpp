#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string m_target;
	
	PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	virtual ~PresidentialPardonForm();

protected:
	void	action() const;
};

#endif