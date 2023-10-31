#include "./Span/Span.hpp"
#include <iostream>
#include <ctime>
#include <array>

int main()
{
	{
	try
	{
	std::cout << "\n===================Copy constructor and tests=======================" << std::endl;
	srand(std::time(NULL));
	const int N = 10000;
	std::vector<int> randomNumbers(N, 0);

	for(int i = 0; i < N; i++)
			randomNumbers[i] = rand();

	Span test(N);	
	test.fillSpan(randomNumbers.begin(), randomNumbers.end());
	Span copyTest(test);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << copyTest.shortestSpan() << std::endl;
	std::cout << copyTest.longestSpan() << std::endl;
	std::cout << "\n==================Copy assigment and tests========================" << std::endl;

	copyTest.getData().clear();
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	for(int i = 0; i < N; i++)
			randomNumbers[i] = rand();
	copyTest.fillSpan(randomNumbers.begin(), randomNumbers.end());
	test = copyTest;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << copyTest.shortestSpan() << std::endl;
	std::cout << copyTest.longestSpan() << std::endl;

	std::cout << "\n=================PDF Test=========================" << std::endl;

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

}