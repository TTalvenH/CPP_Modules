#include "./Character/Character.hpp"
#include "./MateriaSource/MateriaSource.hpp"
#include "./Ice/Ice.hpp"
#include "./Cure/Cure.hpp"

int main(){
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(3, *bob);

	Character* newMe = static_cast<Character*>(me);
	AMateria* onGround1 = newMe->getItem(0);
	me->unequip(0);
	AMateria* onGround2 = newMe->getItem(1);
	me->unequip(1);


	delete onGround1;
	delete onGround2;
	delete bob;
	delete me;
	delete src;
	return 0;
}