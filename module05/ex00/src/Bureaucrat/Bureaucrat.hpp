#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat{
private:
	const std::string 	m_name;
	int					m_grade;
public:

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{;
		public:
			virtual const char* what() const throw();
	};
	
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(std::string name, int grade);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string	getName() const;
	int 		getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

};

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureauc);


#endif