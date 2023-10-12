#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++){
		m_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy){
	for (int i = 0; i < 4; i++){
		m_materias[i] = copy.m_materias[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
	if (this != &copy){
		for (int i = 0; i < 4; i++){
			delete m_materias[i]; 
			m_materias[i] = copy.m_materias[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		delete m_materias[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (!m_materias[i]){
			m_materias[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type){
	for (int i = 0; i < 4; i++){
		if (m_materias[i] && m_materias[i]->getType() == type){
			return m_materias[i]->clone();
		}
	}
	return 0;
}