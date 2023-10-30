#include "./Array/Array.hpp"

int main()
{
	Array<std::string> strings(3);
	Array<std::string> empty;
	strings[0] = "Hive";
	strings[1] = "is";
	strings[2] = "the best!!";
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << strings[i] << " ";
	}

	std::cout << "\n==============Deep copy test================" << std::endl;
	Array<std::string> copyStrings(strings);
	copyStrings[0] = "this";
	copyStrings[1] = "is a";
	copyStrings[2] = "copy";

	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;
	
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << copyStrings[i] << " ";
	}
	std::cout << std::endl;
	strings = copyStrings;
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n==============Exception test================" << std::endl;
	Array<int> test;
	try
	{
		test[0];
	}
	catch (std::exception& e)
	{
		std::cout << "Index out of bounds!! " << e.what() << std::endl;
	}
	{
		std::cout << "==============const test===============" << std::endl;
		const Array<int> const_array(10);
		// const_array[0] = 10;
		std::cout << const_array[9] << std::endl;
	}
}