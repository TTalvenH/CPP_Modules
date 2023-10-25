#include "./Easyfind/Easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vecContainer(10);

	for (size_t i = 0; i < vecContainer.size(); i++)
		vecContainer[i] = i + 1;
	try{
	std::cout << *easyfind(vecContainer, 1) << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}



}