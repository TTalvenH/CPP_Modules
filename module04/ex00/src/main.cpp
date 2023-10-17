#include "./Cat/Cat.hpp"
#include "./Dog/Dog.hpp"
#include "./WrongCat/WrongCat.hpp"

int main(){

	{
	std::cout << "\n=========== PDF Tests ================\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n-------------------------\n" << std::endl;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n-------------------------\n" << std::endl;
	
	delete(meta);
	delete(j);
	delete(i);

	}

	{
		std::cout << "\n=========== My Tests ================\n" << std::endl;

		Animal* cat = new Cat();
		Animal* dog = new Dog();
		WrongAnimal* wrong_cat = new WrongCat();

		Dog puppe;
		Dog copy_puppe(puppe);

		Cat kitty;
		Cat copy_kitty(kitty);


		std::cout << "\n-------------------------\n" << std::endl;

		cat->makeSound();
		dog->makeSound();
		wrong_cat->makeSound();


		std::cout << "\n-------------------------\n" << std::endl;


		delete(cat);
		delete(wrong_cat);
		delete(dog);
	}
}