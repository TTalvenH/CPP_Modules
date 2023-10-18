#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137)
, m_target("default"){}
 
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy.getName(), copy.getSigned(), copy.getExecGrade())
, m_target(copy.m_target){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
, m_target(target){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		std::cout << "this is dum don't do this" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::action() const{
	std::string fileName = m_target + "_shrubbery";
	std::ofstream	outFile(fileName.c_str(), std::ios::out);
	if (!outFile.is_open()){
		std::cerr << "Error opening output file!" << std::endl;
	}
	outFile
	<< "  ^   ^   ^    ^    ^  ^   ^  ^  ^   ^  ^  \n"
    << " /|\\ /|\\ /|\\  /|\\  /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
	<< " /|\\ /|\\ /|\\  /|\\  /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
	<< " /|\\ /|\\ /|\\  /|\\  /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n" << std::endl;
}