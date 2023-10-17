#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"
int main(){
	// Animal animal;

	Animal* animals[4];

	for (int i = 0; i < 4; i++){
		if (i < 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;

	}

	std::cout << "\n-----------------------------" << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 4; i++){
		animals[i]->makeSound();
	}
	std::cout << "\n-----------------------------\n" << std::endl;

	Dog originalDog;
	originalDog.getBrain().setIdea(0, "Bark Bark fun fun!");
	std::cout << originalDog.getBrain().getIdea(0) << std::endl;

	std::cout << "\n-----------------------------\n" << std::endl;

	Dog copyDog(originalDog);
	std::cout << copyDog.getBrain().getIdea(0) << std::endl;
	copyDog.getBrain().setIdea(0, "zzzzzz");
	std::cout << copyDog.getBrain().getIdea(0) << std::endl;

	std::cout << "\n-----------------------------\n" << std::endl;

	copyDog = originalDog;
	std::cout << copyDog.getBrain().getIdea(0) << std::endl;
	std::cout << "\n-----------------------------" << std::endl;

	Dog basic;
	basic.getBrain().setIdea(0, "yes yes good idea");
	{
		Dog tmp = basic;
		std::cout << tmp.getBrain().getIdea(0) << std::endl;
	}
	std::cout << basic.getBrain().getIdea(0) << std::endl;
	

	std::cout << "\n-----------------------------" << std::endl;
	
	for (int i = 0; i < 4; i++){
		delete animals[i];
	}
}