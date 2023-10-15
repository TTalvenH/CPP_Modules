#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("default_name"), m_grade(150) {
}
 
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : m_name(copy.m_name), m_grade(copy.m_grade){}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name){
	if (grade > 150) { throw GradeTooLowException(); }
	if (grade < 1) { throw GradeTooHighException(); }
	m_grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		m_grade = other.m_grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string	Bureaucrat::getName() const{ return m_name; }

int	Bureaucrat::getGrade() const{ return m_grade; }

void	Bureaucrat::incrementGrade(){
	m_grade > 1 ? m_grade-- : throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(){
	m_grade < 150 ? m_grade++ : throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& bureauc){
	return out << bureauc.getName() << ", bureaucrat grade " << bureauc.getGrade();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Exception: Grade too high!!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Exception: Grade too low!!";
}