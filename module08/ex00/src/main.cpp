#include "./Easyfind/Easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vecContainer(10);

	for (size_t i = 0; i < vecContainer.size(); i++)
		vecContainer[i] = 5;
	const std::vector<int> constVecContainer(vecContainer);
	try{
	std::cout << *easyfind(vecContainer, 5) << std::endl;
	std::cout << *easyfind(constVecContainer, 5) << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}