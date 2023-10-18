#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class Form{

private:
	const std::string	m_name;
	bool				m_signed;
	const int			m_signGrade;
	const int			m_execGrade;
	Form();
	Form&	operator=(const Form& other);
	
public:

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{;
		public:
			virtual const char* what() const throw();
	};
	
	Form(const Form& copy);
	Form(std::string name, int signGrade, int execGrade);
	~Form();

	std::string	getName() const;
	bool 		getSigned() const;
	int 		getSignGrade() const;
	int 		getExecGrade() const;

	void		beSigned(const Bureaucrat& bureauc);

};

std::ostream&	operator<<(std::ostream& out, Form& form);

#endif