#include "AForm.hpp"

AForm::AForm()
: m_name("default_name")
, m_signed(false)
, m_signGrade(1)
, m_execGrade(1){}
 
AForm::AForm(const AForm& copy) 
: m_name(copy.m_name)
, m_signed(copy.m_signed)
, m_signGrade(copy.m_signGrade)
, m_execGrade(copy.m_execGrade){}

AForm::AForm(std::string name, int signGrade, int execGrade)
: m_name(name)
, m_signed(false)
, m_signGrade(signGrade)
, m_execGrade(execGrade){
	if (m_signGrade > 150 || m_execGrade > 150) { throw GradeTooLowException(); }
	if (m_signGrade < 1 || m_execGrade < 1){ throw GradeTooHighException(); }
}

AForm&	AForm::operator=(const AForm& other){
	if (this != &other){
		m_signed = other.m_signed;
	}
	return *this;
}

AForm::~AForm(){}

std::string	AForm::getName() const{ return m_name; }

bool	AForm::getSigned() const{ return m_signed; }

int	AForm::getSignGrade() const{ return m_signGrade; }

int	AForm::getExecGrade() const{ return m_execGrade; }

std::ostream&	operator<<(std::ostream& out, AForm& form){
	return out
	<< "Name: " << form.getName() 
	<< "\nSigned: " << form.getSigned()
	<< "\nsignGrade: " << form.getSignGrade()
	<< "\nexecGrade: " << form.getExecGrade();
}

const char*	AForm::GradeTooHighException::what() const throw(){
	return "grade is too high!!";
}

const char*	AForm::GradeTooLowException::what() const throw(){
	return "grade is too low!!";
}

const char*	AForm::FormNotSigned::what() const throw(){
	return "Form not signed!!";
}

void	AForm::beSigned(const Bureaucrat& bureauc){
	if (bureauc.getGrade() > m_signGrade){ throw GradeTooLowException(); }
	m_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const{
	if (!getSigned()) { throw FormNotSigned(); }
	if (executor.getGrade() > getExecGrade()) { throw GradeTooLowException(); }
	action();
}
