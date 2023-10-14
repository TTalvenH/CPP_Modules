#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat{
private:
	const std::string 	m_name;
	int					m_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(int grade);
	Bureaucrat&	operator=(const Bureaucrat& copy);
	~Bureaucrat();

};

#endif