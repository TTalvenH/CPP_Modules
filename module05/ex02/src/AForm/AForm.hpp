#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm{

private:
	const std::string	m_name;
	bool				m_signed;
	const int			m_signGrade;
	const int			m_execGrade;

	AForm();
	AForm&	operator=(const AForm& other);
	
public:

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{;
		public:
			virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception{;
		public:
			virtual const char* what() const throw();
	};
	
	AForm(const AForm& copy);
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm();

	std::string	getName() const;
	bool 		getSigned() const;
	int 		getSignGrade() const;
	int 		getExecGrade() const;

	void		beSigned(const Bureaucrat& bureauc);
	void		execute(Bureaucrat const& executor) const;
protected:
	virtual void		action() const = 0;

};

std::ostream&	operator<<(std::ostream& out, AForm& form);

#endif