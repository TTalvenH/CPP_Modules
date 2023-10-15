#include "Form.hpp"

Form::Form()
: m_name("default_name")
, m_signed(false)
, m_signGrade(1)
, m_execGrade(1){}
 
Form::Form(const Form& copy) 
: m_name(copy.m_name)
, m_signed(copy.m_signed)
, m_signGrade(copy.m_signGrade)
, m_execGrade(copy.m_execGrade){}

Form::Form(std::string name, int signGrade, int execGrade)
: m_name(name)
, m_signed(false)
, m_signGrade(signGrade)
, m_execGrade(execGrade){
	if (m_signGrade > 150 || m_execGrade > 150) { throw GradeTooLowException(); }
	if (m_signGrade < 1 || m_execGrade < 1){ throw GradeTooHighException(); }
}

Form&	Form::operator=(const Form& other){
	if (this != &other){
		m_signed = other.m_signed;
	}
	return *this;
}

Form::~Form(){}

std::string	Form::getName() const{ return m_name; }

bool	Form::getSigned() const{ return m_signed; }

int	Form::getSignGrade() const{ return m_signGrade; }

int	Form::getExecGrade() const{ return m_execGrade; }

std::ostream&	operator<<(std::ostream& out, Form& form){
	return out
	<< "Name: " << form.getName() 
	<< "\nSigned: " << form.getSigned()
	<< "\nsignGrade: " << form.getSignGrade()
	<< "\nexecGrade: " << form.getExecGrade();
}

const char*	Form::GradeTooHighException::what() const throw(){
	return "grade is too high!!";
}

const char*	Form::GradeTooLowException::what() const throw(){
	return "grade is too low!!";
}

void	Form::beSigned(const Bureaucrat& bureauc){
	if (bureauc.getGrade() > m_signGrade){ throw GradeTooLowException(); }
	m_signed = true;
}
