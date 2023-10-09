#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"
int main(){
	// Animal test;
	Animal* animals[4];

	for (int i = 0; i < 4; i++){
		if (i < 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;

	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++){
		animals[i]->makeSound();
	}

	// dynamic_cast<Dog*>(animals[0])->getBrain().setIdea(101, "Bark dynamic_cast is cool Bark!");
	// std::cout << dynamic_cast<Dog*>(animals[0])->getBrain().getIdea(101) << std::endl;

	std::cout << std::endl;
	Dog originalDog;

	originalDog.getBrain().setIdea(0, "Bark Bark fun fun!");
	Dog copyDog(originalDog);
	copyDog.getBrain().setIdea(0, "zzzzzz");
	std::cout << std::endl;
	std::cout << originalDog.getBrain().getIdea(0) << std::endl;
	std::cout << copyDog.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;
	copyDog = originalDog;
	std::cout << copyDog.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++){
		delete animals[i];
	}
}