#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

#include "../Form/Form.hpp"

class Form;

class Bureaucrat{
private:
	const std::string 	m_name;
	int					m_grade;
	Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& other);
	
public:

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{;
		public:
			virtual const char* what() const throw();
	};
	
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	std::string	getName() const;
	int 		getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

	void		signForm(Form& form) const;
};

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureauc);


#endif